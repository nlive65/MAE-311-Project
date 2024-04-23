import pandas as pd
import pyodbc
import json

#Gets the Database configuration and 
#permission login data
apiData = {}
with open('APISecrets.json') as f:
    apiData = json.load(f)
server = apiData['server']
database = apiData['db']
username = apiData['username']
password = apiData['password']
driver = '{ODBC Driver 18 for SQL Server}'
#Creates a connection to the SQL server
conn = pyodbc.connect(f'DRIVER={{ODBC Driver 18 for SQL Server}};SERVER={server};DATABASE={database};UID={username};PWD={password};Encrypt=no;TrustServerCertificate=yes')

#Select all data
sql_query = "SELECT * FROM run.PacketData"
df = pd.read_sql(sql_query,conn)#Save the data to a multidimensional array structure

conn.close()

excel_File = "output.xlsx"
#export the data to an excel file
df.to_excel(excel_File,index=False)
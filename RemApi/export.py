import pandas as pd
import pyodbc
import json
apiData = {}
with open('APISecrets.json') as f:
    apiData = json.load(f)
server = apiData['server']
database = apiData['db']
username = apiData['username']
password = apiData['password']
driver = '{ODBC Driver 18 for SQL Server}'
conn = pyodbc.connect(f'DRIVER={{ODBC Driver 18 for SQL Server}};SERVER={server};DATABASE={database};UID={username};PWD={password};Encrypt=no;TrustServerCertificate=yes')

sql_query = "SELECT * FROM run.PacketData"
df = pd.read_sql(sql_query,conn)

conn.close()

excel_File = "output.xlsx"
df.to_excel(excel_File,index=False)
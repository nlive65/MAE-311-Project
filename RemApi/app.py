from flask import Flask, request, jsonify
import pyodbc
import json 

#Gets the Database configuration and 
#permission login data
apiData = {}
with open('APISecrets.json') as f:
    apiData = json.load(f)

app = Flask(__name__)

server = apiData['server']
database = apiData['db']
username = apiData['username']
password = apiData['password']
driver = '{ODBC Driver 18 for SQL Server}'
#Creates connection to the SQL database
cnxn = pyodbc.connect(f'DRIVER={{ODBC Driver 18 for SQL Server}};SERVER={server};DATABASE={database};UID={username};PWD={password};Encrypt=no;TrustServerCertificate=yes')
cursor = cnxn.cursor()


def isValid(data):
    #Checks if the received packet is valid before allowing to be inserted
    #If not throws a server side error
    if not isinstance(data['PacketType'],list):
        raise Exception("Packet Type invalid")
    if not isinstance(data['MagX'],float):
        raise Exception("Magnetic X invalid")
    if not isinstance(data['MagY'],float):
        raise Exception("Magnetic Y invalid")
    if not isinstance(data["MagZ"],float):
        raise Exception("Magnetic Z invalid")
    if not isinstance(data['Temp'],float):
        raise Exception("Temperature invalid")
    if not isinstance(data['time'],int):
        raise Exception("Time invalid")

@app.route('/insert_data',methods=['POST'])#When data is sent to the API
def insert_data():
    #Get the data
    data = request.json
    if data:
        try:
            isValid(data)
            #IF the data is valid, inserts the data into the database
            cursor.execute("INSERT INTO run.PacketData (PacketType,MagX,MagY,MagZ,Temp,time) VALUES (?,?,?,?,?,?)",
            (data['PacketType'],data['MagX'],data['MagY'],data['MagZ'],data['Temp'],data['time']))
            cnxn.commit()
            #returns successful message
            return jsonify({'message':'Data inserted successfully'}),200
        except Exception as e:
            #Return what error occured
            return jsonify({'error':str(e)}),500
    else:
        #Empty packet case
        return jsonify({'error':'No data provided'}),400

if __name__=='__main__':
    #Host the flask API
    app.run(host='0.0.0.0')
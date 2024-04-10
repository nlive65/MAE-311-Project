from flask import Flask, request, jsonify
import pyodbc
import json 


apiData = {}
with open('APISecrets.json') as f:
    apiData = json.load(f)

app = Flask(__name__)

server = apiData['server']
database = apiData['db']
username = apiData['username']
password = apiData['password']
driver = '{ODBC Driver 18 for SQL Server}'
cnxn = pyodbc.connect(f'DRIVER={{ODBC Driver 18 for SQL Server}};SERVER={server};DATABASE={database};UID={username};PWD={password};Encrypt=no;TrustServerCertificate=yes')
cursor = cnxn.cursor()


def isValid(data):
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

@app.route('/insert_data',methods=['POST'])
def insert_data():
    data = request.json
    if data:
        try:
            isValid(data)
            cursor.execute("INSERT INTO run.PacketData (PacketType,MagX,MagY,MagZ,Temp,time) VALUES (?,?,?,?,?,?)",
            (data['PacketType'],data['MagX'],data['MagY'],data['MagZ'],data['Temp'],data['time']))
            cnxn.commit()
            return jsonify({'message':'Data inserted successfully'}),200
        except Exception as e:
            return jsonify({'error':str(e)}),500
    else:
        return jsonify({'error':'No data provided'}),400

if __name__=='__main__':
    app.run(host='0.0.0.0')
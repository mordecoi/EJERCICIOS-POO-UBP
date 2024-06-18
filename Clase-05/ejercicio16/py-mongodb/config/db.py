from pymongo import MongoClient

conn = MongoClient('mongodb://localhost:27017/')
db = conn['POO']
collection = db['Usuarios']
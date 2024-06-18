from fastapi import APIRouter
from models.user import Usuario
from config.db import conn
from schemas.user import userEntity, usersEntity
from bson import ObjectId as objectId

user = APIRouter()

@user.get('/')
async def find_all_users():
    return usersEntity(conn.POO.Usuarios.find())

@user.get('/{id}')
async def find_one_user(id: str):
    return userEntity(conn.POO.Usuarios.find_one({"_id":objectId(id)}))

@user.post('/')
async def create_user(user: Usuario):
    conn.POO.Usuarios.insert_one(dict(user))
    return usersEntity(conn.POO.Usuarios.find())

@user.put('/{id}')
async def update_user(id, user: Usuario):
    conn.POO.Usuarios.find_one_and_update({"_id":objectId(id)}, {"$set": dict(user)})
    return userEntity(conn.POO.Usuarios.find_one({"_id":objectId(id)}))

@user.delete('/{id}')
async def delete_user(id: str):
    return userEntity(conn.POO.Usuarios.find_one_and_delete({"_id":objectId(id)}))
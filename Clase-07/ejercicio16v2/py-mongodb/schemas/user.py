def userEntity(item) -> dict:
    return {
        "id": str(item["_id"]),
        "nombre": item["nombre"],
        "apellido": item["apellido"],
        "usuario": item["usuario"],
        "clave": item["clave"],
    }

def usersEntity(entity) -> list:
    return [userEntity(item) for item in entity]
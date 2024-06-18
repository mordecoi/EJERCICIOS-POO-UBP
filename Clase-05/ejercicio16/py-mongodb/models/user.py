from pydantic import BaseModel

class Usuario(BaseModel):
    nombre: str
    apellido: str
    usuario: str
    clave: str
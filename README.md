# Holy Cats API

Honly Cats API es una API REST desarrollada en C, diseñada para ofrecer un servicio ligero y eficiente para la gestión y consulta de información relacionada con gatos. El proyecto prioriza el rendimiento, la simplicidad y una arquitectura fácil de mantener.

## Características

* API REST basada en HTTP.
* Respuestas en formato JSON.
* Operaciones CRUD para recursos de gatos.
* Arquitectura modular y extensible.
* Alto rendimiento y bajo consumo de recursos.
* Fácil integración con aplicaciones y servicios externos.

## Requisitos

* GCC o cualquier compilador compatible con C99.
* `libmicrohttpd`
* `make`

## Instalación

Clone el repositorio:

```bash
git clone https://github.com/kittyhos/holy-cats.git
cd honly-cats
```

Compile el proyecto:

```bash
make
```

Ejecute el servidor:

```bash
./honly-cats
```

Por defecto, la API estará disponible en:

```
http://localhost:8080
```

## Endpoints

| Método | Endpoint     | Descripción                           |
| ------ | ------------ | ------------------------------------- |
| GET    | `/cats`      | Obtiene la lista de gatos.            |
| GET    | `/cats/{id}` | Obtiene un gato por su identificador. |
| POST   | `/cats`      | Crea un nuevo registro.               |
| PUT    | `/cats/{id}` | Actualiza un registro existente.      |
| DELETE | `/cats/{id}` | Elimina un registro.                  |

## Ejemplo de respuesta

```json
{
  "id": 1,
  "name": "Michi",
  "age": 2
}
```

## Objetivos

* Proporcionar una implementación de referencia de una API REST en C.
* Servir como base para proyectos que requieran un servidor HTTP ligero.
* Mantener una base de código clara, modular y fácil de extender.

## Contribuciones

Las contribuciones son bienvenidas. Para cambios importantes, se recomienda abrir un *Issue* para discutir la propuesta antes de enviar un *Pull Request*.

## Licencia

Este proyecto se distribuye bajo la licencia GNU. Consulte el archivo `LICENSE` para más información.

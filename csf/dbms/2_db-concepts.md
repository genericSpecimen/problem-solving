# DB System Concepts
## Data Model
* collection of concepts used to describe the structure of a database - data types, relationships, constraints
* provides means to achieve data abstraction
* provides basic operations for specifying retrievals and updates on the DB.
* three main categories:
    1. High-level or conceptual data models (based on entities and relationships): concepts close to the way many users perceive data
    2. Low-level or physical data models: details of how data is stored on computer storage media - meant for computer specialists, not end users.
    3. Representational or implementation data models (record-based, object-oriented) - easily understood by end users, but not too far removed from the way data is organized in computer storage
* The third is the most frequently used in traditional commerical DBMSs, this includes the relational data model.
* Physical data model - record formats, record orderings, access paths - search structure that makes the search for particular DB record efficient, such as indexing or hashing. index is an access path that allows direct access to data using an index term or a keyword.

## Schemas
* DB schema : description of the DB - specified during DB design, not expected to change frequently
* Most data models have conventions for displaying schemas as diagrams - shows the structure of each record type
* schema construct - each object in the schema
* schema evolution - changes to the schema as the appln requirements change.
## Instances
* DB state / snapshot - data in the DB at a particular moment in time - current set of occurences or instances.
* DBMS ensures that every state of the DB is a valid state - satisfies structure and constraints specified in the DB schema.

## DBMS Languages

### specify schema

* DDL (data defn lang) - define conceptual schemas. (internal schema as well if no clear distinction between levels)
* SDL (storage defn lang) - used to specify internal schema - in most RDBMSs, no such specific Language - instead, internal schema specified by a combo of functions, params, and specs related to storage of files - allows DBA to control indexing choices and mapping of data to storage
* VDL (view defn lang) - specify user views and their mappings to conceptual schema. in most DBMSs, the DDL is used to define both conceptual and external schemas. eg: results of predefined SQL queries in RDBMSs

### DB manipulation

* DML (data manipulation lang) - retrieval, insertion, deletion, modification of data

### Comprehensive DB Lang
* includes constructs for conceptual schema defn, view defn, data manipulation
* storage defn typically kept separate since it is used for defining physical storage structures to fine tune performance of the DB system.
* eg: SQL relational DB lang represents:
    * a combo of DDL, VDL, and DML
    * statements for constraint specification, schema evolution
    
## Classification of DBMS
* based on data model
    * relational data model - widely used in commerical applns. systems based on this model are called SQL systems.
        * represents a DB as a collection of tables
        * each table can be stored as a separate files
        * most RDB use SQL
    * object data model - implemented in some commerical systems but not widespread.
        * defines a DB in terms of objects, their properties, and their operations
        * objects with same structure and behaviour belong to a class, and classes are organized into hierarchies.
    * big data systems / key-value storage systems, NoSQL systems, use various data models - document-based, graph, column, key-value data models.
* number of users
    * single user systems - support only one user at a time, mostly used with PCs
    * multi user systems - majority of DBMSs, support concurrent multiple users.
* number of sites over which the DB is distributed
    * centralized - data stored at a single computer site
    * distributed - actual DB and DBMS software can be distributed over multiple sites connected by a computer network
* cost - open source products like MariaDB, PostgreSQL
* types of access path options for storing files
* general purpose / special purpose

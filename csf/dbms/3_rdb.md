# Relational Model

## Relational Data Model
* represents DB as a collection of relations
* each relation is like a table of values
    * each row in the table represents a collection of related data values - it represents a fact that corresponds to a real world entity / relationship. 
    * table name and column names are used to interpret the meaning of the values in each row. 
    * relation = table, row = tuple, column header = attribute

## Relational Model Constraints
* various restrictions / Constraints on the actual values in a DB state
* three main categories:
    1. implicit / inherent model based Constraints. eg: a relation can't have duplicate tuples, each value in a tuple must be atomic - composite, multi valued attrs not allowed and must be represented by separate relations.
    2. explicit / schema based Constraints - can be directly expressed in the schemas of the data model, typically using DDL
    3. application based / semantic Constraints - can't be directly expressed in the schemas of the data model, therefore must be expressed and enforces by the appln pgms or in some other way(constraint spec lang, mechanisms like triggers and assertions in SQL). eg. salary of employee should not exceed the salary of their supervisor
### explicit / schema based constraints : domain, key, NOT NULL
* domain constraints: in each tuple, value of each attribute must be an atomic value from the domain of that attribute
* key constraints and constraints on null values:
    * Superkey
        * subset of attrs of a relation schema R with the property that no two tuples in any relation state should have the same combo of values for these attrs
        * any such set of attrs is called a superkey SK of the relation schema R
        * SK specifies a uniqueness constraint.
    * Key - minimal superkey
        * superkey of relation R such that removing any attr from it leaves a set of attrs that is not a superkey or R.
    * value of a key attr can be used to identify uniquely each tuple in the relation
    * a relation schema may have more than one key - each is called a candidate key.
    * primary key - candidate key chosen to identify tuples in the relation (underlined). other candidate keys are called unique keys (not underlined)
    * constraint on attrs: whether NULL values are permitted
    

## Relational Database Schema
* set of relation schemas and a set of integrity constraints
* RDB state: a set of relation states such that each relation state satisfies the integrity constraints

### Entity integrity constraint
* no primary key value can be NULL - because it means we can't identify some tuples
* key and entity integrity constraints is on a single relation

### Referential integrity constraint
* b/w two relations
* used to maintain consistency among tuples in two relations
* a tuple in one relation that refers to another relation must refer to an existing tuple in that relation

* foreign key: a set of attrs FK in one relation R1 is a foreign key of R1 that references relation R2 if it satisfies:
    * attrs in FK have the same domain(s) as the PK of R2
    * FK can be NULL or must refer to an existing tuple in R2
    * R1: referencing relation, R2: referenced relation
* a foreign key can refer to its own relation
* directed arrow from each FK to the PK of the relation it references


### SQL DDL and constraints
* CREATE TABLE allows defn of PK, unique key, NOT NULL, entity integrity referential integrity constraints
* CREATE TRIGGER, CREATE ASSERTION

    
### Update Operations: insert, update, delete
* whenever these ops are applied, the integrity constraints specified on the RDB schema should not be violated.
* insert can violate any of the four types of constraints. default option - reject the insertion
* delete can only violate referential integrity - tuple being deleted is referenced by FKs from other tuples in the DB. options:
    * RESTRICT : reject the deletion
    * CASCADE : attempt to cascade (propagate) the deletion by deleting tuples that reference the tuple being deleted
    * SET NULL / SET DEFAULT - modify the referencing attr values that cause the violation.
* Updating an attr that's neither a part of PK or FK usually causes no problems, except domain and NOT NULL.
    * updating PK = deleting a tuple + adding a new tuple ... same violations possible
    * updating FK : referential integrity violation

## The Transaction Concept
* a DB appln pgm running with a RDB typically executes one or more transactions.
* executing pgm that includes some DB operations (CRUD)
* at the end of the transaction, it must leave the DB in a valid / consistent state that satisfies all the constraints specified on the DB schema
* eg: transaction to apply a bank withdrawal
    1. read the user account record
    2. check if there is a sufficient balance
    3. update the record by the withdrawal amount
* issues: concurrent execution of transactions, recovery from failures



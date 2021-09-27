# Basic SQL
* Structured Query Language
* standard language for commercial RDBMs
* comprehensive language - both DDL and DML
* provides a high level declarative lang interface:
    * user only specifies what the result is to be
    * leaves actual optimizations and decisions on how to execute the query to the DBMS
* allows two identical tuples in a table - multiset (instead of set) of tuples
* some SQL relations are constrained to be sets because of key constraints.

## SQL DDL
* CREATE - schemas, tables, types, domains, views, assertions, triggers

### SQL Schema
* CREATE SCHEMA Company AUTHORIZATION 'JSmith';
* identified by schema name and includes an authorization identifier to indicate the user / account who owns the schema
* descriptors for each element in the schema
* elements desribe the schema: tables, types, constraints, views, domains, authorization grants

* SQL catalog - named collection of schemas
* SQL installations - default env and schema - user can directly refer to tables and constructs within that schema without having to specify a particular schema name
* INFORMATION_SCHEMA: special schema - provides info on all the schemas in the catalog and all the element descriptors in these schemas

### CREATE TABLE
* creates a new relation - specify name, attrs, initial constraints
* SQL schema in which the relations are declared is implicitly defined in the env in which the stmt is executed
* CREATE TABLE COMPANY.EMPLOYEE == CREATE TABLE EMPLOYEE
* CREATE TABLE creates a base relation - actually created and stored as a file by the DBMS
* CREATE VIEW creates a virtual relation, which may or may not correspond to an actual physical file.
* CREATE DOMAIN SSN_TYPE AS CHAR(9)
* CREATE TYPE - user defined types

### Constraints in SQL
* NOT NULL
    * if NULL is not permitted for a particular attr.
    * implicitly specified for attrs that are part of the primary key of each relation
* DEFAULT <value> to define a default value for an attribute. default _default value_ is NULL for attrs that don't have NOT NULL constraint.
* CHECK to restrict attr or domain values.
    * Dept_no INT NOT NULL CHECK(Dept_no > 0 AND Dept_no < 21);
    * CREATE DOMAIN D_NUM AS INTEGER CHECK (D_NUM > 0 AND D_NUM < 21);
 
* PRIMARY KEY clause
    * specifies one or more attrs that make up the PK of a relation
    * if PK has a single attr, it can follow the attr directly - Dnum INT PRIMARY KEY
* UNIQUE clause
    * specifies alternate unique keys
    * Dname VARCHAR(15) UNIQUE

* Referential integrity - FOREIGN KEY clause
    * FOREIGN KEY (Dnum) REFERENCES DEPARTMENT(Dnumber)
    * default action for Referential integrity violation - restrict - reject the operation
    * instead, we can attach a referential triggered action clause to any FK constraint - SET NULL, CASCADE, SET DEFAULT
    * ON DELETE SET NULL - if referenced tuple is deleted, set the attr value of all referring tuples to NULL.
    * ON UPDATE CASCADE - propagate the updated value of the referred tuple through to the referring tuple. change the value of the referencing FK attrs to the updated (new) PK value for all the referencing tuples.
    * ON DELETE CASCADE - delete all the referencing tuples
* name constraints using optional CONSTRAINT clause.
* constraints on tuples using CHECK - row based constraints - apply to each row individually and are checked whenever a new row is inserted / modified. CHECK (Dept_create_date <= Mgr_start_date)

### Retrieval

SELECT \[DISTINCT\] \<attr list\>
FROM \<table list\>
\[WHERE \<condition\>\]
\[ORDER BY \<attr list\>\]
\[GROUP BY \<grouping attrs\>\]
\[HAVING \<group condition\>\]
\[ORDER BY \<attr list\>\];

join condition - combines two tuples from two relations


### Insertion
INSERT INTO <relation>
VALUES (..)

### DELETE
DELETE FROM <relation>
WHERE <condition>

### UPDATE
UPDATE <relation>
SET \<attr=value list\>
WHERE \<condition\>

to modify multiple relations, we need to use multiple UPDATEs

### NULL
* IS NULL, IS NOT NULL

### IN
* id IN (1, 2, 3)

### EXISTS, UNIQUE
* return T/F
* EXISTS, NOT EXISTS: check whether the result of a nested query is not empty or empty.
* UNIQUE : returns true if there are no duplicate tuples in the result of query

### Joined tables
* Natural Join on two tables R and S - no join condition specified - an implicit EQUIJOIN condition for each pair of attrs is included only once in the resulting relation.
* NATURAL used when join attrs have same names

* INNER JOIN, or JOIN
    * default type of join in a joined table
    * a tuple is included in the result only if a matching tuple exists in the other relation
    * only pairs of tuples that match the join condition are retrieved
* OUTER JOIN
    * LEFT OUTER JOIN - every tuple in the left table must appear in the result. if it does not have a matching tuple, it's padded with NULL values for the attrs of the right table.
    * RIGHT OUTER JOIN - every tuple in the right table must appear in the result. if it does not have a matching tuple, it's padded with NULL values for the attrs of the left table.
    * FULL OUTER JOIN - combination of LEFT and RIGHT

* CROSS JOIN - cartesian product operation - generates all possible tuple combinations

### Schema Change Stmts in SQL
* schema evolution commands - alter a schema by adding or dropping tables, attrs, constraints, or other schema elements
* DROP named schema elements - tables, domains, types, constraints, DROP SCHEMA - entire schema
    * DROP SCHEMA COMPANY \[RESTRICT\]; only if it has no elements in it
    * DROP SCHEMA COMPANY CASCADE; drops all its tables, domains, other elems as well
    * DROP TABLE tablename CASCADE: table + constraints, views, other elems that refer tablename are dropped.
    * DROP TABLE also removes table defn from the catalog. to delete only records, use DELETE command
* ALTER named schema elements - for tables, add / drop column, change column defn, add/drop table constraints
    * ALTER TABLE tblname ADD COLUMN col type
    * ALTER TABLE tblname DROP COLUMN addr CASCADE - all constraints and views that reference the column are dropped from the schema, along with the column
    

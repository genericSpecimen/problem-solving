# Informal Design Guidelines for Relation Schemas

four informal guidelines that may be used as measures to determine the quality of relation 
schema design:
1. Making sure that the semantics of the attributes is clear in the schema:
    * Design a relation schema so that it is easy to explain its meaning.
    * Do not combine attributes from multiple entity types and relationship types into a single relation.
    * if a relation schema corresponds to one entity type or one relationship type, it is straightforward to explain its meaning.
    * Otherwise, if the relation corresponds to a mixture of multiple entities and relationships, semantic ambiguities will result and the relation cannot be easily explained.
2. Reducing the redundant information in tuples:
    * Design the base relation schemas so that no insertion, deletion, or modification anomalies are present in the relations.
    * If any anomalies are present, note them clearly and make sure that the programs that update the database will  operate correctly.
    * Update Anomalies - undesirable side-effects may arise in relations that have not been sufficiently normalized. They cause difficulties to maintain consistency of data as well as require unnecessary updates that can be avoided:
        * Insertion: There are circumstances in which certain facts cannot be recorded at all. eg. faculty and course. A faculty may not be assigned a course yet, or a course may not be taught by a faculty yet. Need to store nulls.
        * Deletion: deletion of data representing certain facts necessitates deletion of data representing completely different facts. eg. All information about a faculty is lost if he or she temporarily ceases to be assigned to any courses.
        * Updation: The same information can be expressed on multiple rows; therefore updates to the relation may result in logical inconsistencies. eg. an employee and their (multiple) skills are stored in diff rows. EMP_ID EMP_NAME, EMP_ADDR, SKILLS. To update EMP_ADDR, all tuples must be updated. if update is not successful on all rows, then DB is in an inconsistent state.
3. Reducing the NULL values in tuples
    * As far as possible, avoid placing attributes in a base relation whose values may frequently be NULL.
    * If NULLs are unavoidable, make sure that they apply in exceptional cases only and do not apply to a majority of tuples in the relation.
    * eg: if only 15% of employees have individual offices, there is little justification for including an attribute Office_number in the EMPLOYEE relation; rather, a relation EMP_OFFICES(Essn, Office_number) can be created to include tuples for only the employees with individual offices.
    
4. Disallowing the possibility of generating spurious tuples:
    * Design relation schemas so that they can be joined with equality conditions on attributes that are appropriately related (primary key, foreign key) pairs in a way that guarantees that no spurious tuples are generated.
    * Avoid relations that contain matching attributes that are not (foreign key, primary key) combinations because joining on such attrs may produce spurious tuples.


# Normalization of data
*  Normalization of data can be considered a process of analyzing the given relation schemas based on their FDs and primary keys to achieve the desirable properties of (1) minimizing redundancy and (2) minimizing the insertion, deletion, and update 
anomalies.
* It can be considered as a “filtering” or “purifi-
cation” process to make the design have successively better quality.
* An unsatisfactory relation schema that does not meet the condition for a normal form—the normal form test—is decomposed into smaller relation schemas that contain a subset of the attributes and meet the test that was otherwise not met by the original relation.

## 1NF
* disallows multi-valued attributes (set/tuple of values)
* disallows relations within relations or relations as attrs within tuples
* only single atomic (indivisible) values attr values are allowed

## 2NF
* A relation schema R is in 2NF if every non candidate key attribute A in R is fully functionally dependent on the primary key of R.

## 3NF
a relation schema R is in 3NF if it satisfies 2NF and no nonprime attribute of R is transitively dependent on the primary key.

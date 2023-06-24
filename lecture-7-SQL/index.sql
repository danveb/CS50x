-- Indexes
-- allows data to be optimized within a table
-- can be used to speed up our queries

-- sqlite> .timer
-- sqlite> .timer on

SELECT * FROM shows WHERE title = 'The Office';
+----------+------------+------+----------+
|    id    |   title    | year | episodes |
+----------+------------+------+----------+
| 112108   | The Office | 1995 | 6        |
| 290978   | The Office | 2001 | 14       |
| 386676   | The Office | 2005 | 188      |
| 1791001  | The Office | 2010 | 30       |
| 2186395  | The Office | 2012 | 8        |
| 8305218  | The Office | 2019 | 28       |
| 20877972 | The Office | 2022 | 20       |
+----------+------------+------+----------+
Run Time: real 0.034 user 0.032968 sys 0.000476

-- CREATE INDEX name_of_index ON table_name (name_of_column)
CREATE INDEX title_index ON shows (title);
Run Time: real 0.352 user 0.227678 sys 0.019340

-- this creates a b-tree (NOT binary tree, but similar because it has a root node and more than 2 leaf nodes)

-- re-run SELECT query... and it's much faster to query
SELECT * FROM shows WHERE title = 'The Office';
+----------+------------+------+----------+
|    id    |   title    | year | episodes |
+----------+------------+------+----------+
| 112108   | The Office | 1995 | 6        |
| 290978   | The Office | 2001 | 14       |
| 386676   | The Office | 2005 | 188      |
| 1791001  | The Office | 2010 | 30       |
| 2186395  | The Office | 2012 | 8        |
| 8305218  | The Office | 2019 | 28       |
| 20877972 | The Office | 2022 | 20       |
+----------+------------+------+----------+
Run Time: real 0.000 user 0.000241 sys 0.000079

-- Trade offs?
-- while indexing may result in much faster queries, it'll take up much more memory...
-- best practice? index some columns...
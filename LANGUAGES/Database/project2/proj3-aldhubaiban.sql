--  Before you try the code in this file from the psql client, you need to create your database NBA-xxx and copy data from NBA to it. For example,
--  createdb NBA-tuy
--  pg_dump -t player_rs_career NBA | psql NBA-tuy
--  Note that those should be done under the Linux console. Then you can log into NBA-xxx and try the following scripts.

--  The following line only needs to be executed once before you do anything at all with pgplsql functions
-- CREATE LANGUAGE 'plpgsql';


-- function 1 declaration

CREATE OR REPLACE FUNCTION nba_efficiency (fn VARCHAR, lsn VARCHAR) RETURNS INT AS $$
DECLARE
efficient INT :=0;
BEGIN
SELECT INTO efficient( (P.pts)+ (P.reb)+ (P.stl)+ (P.asts)+(P.blk) -(P.turnover)- ((P.fga-P.fgm) + (P.fta-P.ftm) + (P.tpa-P.tpm))  )
FROM player_rs_career AS P 
WHERE P.firstname=$1 AND P.lastname=$2;
RETURN efficient;

END;
$$ LANGUAGE plpgsql;


-- function 2 declaration

CREATE OR REPLACE FUNCTION body_mass_index (fn VARCHAR, lsn VARCHAR) RETURNS FLOAT AS $$
DECLARE
BMI FLOAT :=0.0;
BEGIN
-- the function body goes here
SELECT INTO BMI  (weight*.45)/( ((P.h_feet *30.48 + P.h_inches *2.54)/100) *((P.h_feet *30.48 + P.h_inches *2.54)/100) )
FROM players AS P
where P.firstname=$1 and P.lastname=$2;
--CHECK FOR NULL RESULT
if BMI IS NULL
THEN
RETURN 0.0;

ELSE
RETURN BMI;

END IF;

END;
$$ LANGUAGE plpgsql;

-- executing the above functions
-- select * from nba_efficiency('Reggie', 'Miller');
-- select * from body_mass_index('Alaa', 'Abdelnaby');


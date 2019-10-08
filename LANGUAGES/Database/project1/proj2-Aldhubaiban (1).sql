-- Q1 
SELECT firstname,lastname,cid FROM coaches_season GROUP BY firstname,lastname,cid HAVING   COUNT (DISTINCT tid)=1 ORDER BY cid ASC ;
-- Q2
SELECT  DISTINCT firstname,ilkid FROM player_rs WHERE player_rs.tid='BOS' OR player_rs.tid='DEN' GROUP BY ilkid,firstname HAVING count(DISTINCT player_rs.tid)=2 ;
-- Q3 INTERSECTION 
SELECT r.firstname,r.lastname,t.name,c.year FROM (player_rs r INNER JOIN coaches_season c ON c.tid=r.tid AND c.year=r.year AND c.cid=r.ilkid) INNER JOIN teams t ON c.tid=t.tid ORDER BY c.year;
-- Q4
SELECT  t.name,c.firstname,c.lastname,c.year, AVG (p.h_feet *30.48 + p.h_inches *2.54) AS avg_h FROM teams t, coaches_season c, players p,   player_rs pr  WHERE p.ilkid=pr.ilkid AND c.year='2001' AND t.tid=c.tid AND pr.tid=c.tid AND pr.year=c.year
GROUP BY t.name,c.firstname,c.lastname,c.year
ORDER BY avg_h DESC  ;
-- Q5 
SELECT DISTINCT  c.firstname, c.lastname, c.cid FROM coaches_season c,player_rs pr 
WHERE c.year='1999' AND c.tid=pr.tid AND c.year=pr.year 
GROUP BY c.firstname,c.lastname,c.cid
HAVING COUNT (pr.ilkid)= (SELECT MAX (y.num) FROM (SELECT count(*) AS num FROM coaches_season c, player_rs pr 
WHERE c.year='1999' AND c.year=pr.year AND c.tid=pr.tid GROUP BY c.cid) y);
-- Q6 
SELECT DISTINCT c.firstname,c.lastname ,c.cid  FROM coaches_season c , player_rs t WHERE t.tid= c.tid GROUP BY c.firstname, c.cid,c.firstname,c.lastname
HAVING COUNT (DISTINCT t.league)=2 ORDER BY c.firstname asc; 
 -- Q7 
SELECT   c.firstname, c.lastname, c.year,t.name , t1.name    
FROM coaches_Season c 
INNER JOIN  player_rs r ON c.cid=r.ilkid AND c.year=r.year AND c.tid!=r.tid 
INNER JOIN teams t ON r.tid= t.tid
INNER JOIN teams t1 ON c.tid=t1.tid ;
-- Q8 
SELECT firstname,lastname,(pts-(SELECT pts FROM player_rs_career WHERE firstname='Michael' AND lastname='Jordan'))  
FROM player_rs_career GROUP BY firstname,lastname,pts HAVING pts> (SELECT pts FROM player_rs_career WHERE firstname='Michael' AND lastname='Jordan') ORDER BY pts DESC ;
-- Q9
SELECT   firstname,lastname, ( SUM ( CAST (season_win AS FLOAT  )) /   SUM ( CAST (season_win AS FLOAT  ) + CAST (season_loss AS FLOAT  ) ) )  sucess FROM coaches_season GROUP BY firstname,lastname ORDER BY sucess DESC LIMIT 1 OFFSET 1;
-- Q10 
SELECT draft_from ,COUNT(DISTINCT ilkid) FROM draft GROUP BY  draft_from  ORDER BY count(ilkid) DESC  LIMIT 3;
 


 


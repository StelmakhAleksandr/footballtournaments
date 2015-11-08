 DECLARE @i INT;SET @i=0;
 SELECT t.*,p.*,
(SELECT count(Distinct(sm.Id)) FROM Matches sm,Parts sp where sp.champid=p.champid AND ((sm.partsid1=p.id) or (sm.partsid2=p.id)) )as game,
(SELECT count(Distinct(sm.Id)) FROM Matches sm,Parts sp where sp.champid=p.champid AND ((sm.partsid1=p.id AND sm.g1>sm.g2) or (sm.partsid2=p.id AND sm.g2>sm.g1))  )as win,
(SELECT count(Distinct(sm.Id)) FROM Matches sm,Parts sp where sp.champid=p.champid AND ((sm.partsid1=p.id AND sm.g1=sm.g2) or (sm.partsid2=p.id AND sm.g2=sm.g1))  )as draw,
(SELECT count(Distinct(sm.Id)) FROM Matches sm,Parts sp where sp.champid=p.champid AND ((sm.partsid1=p.id AND sm.g1<sm.g2) or (sm.partsid2=p.id AND sm.g2<sm.g1))  )as defeat,
(SELECT ISNULL(sum(Distinct(sm.g1)),0) FROM Matches sm,Parts sp where sp.champid=p.champid AND (sm.partsid1=p.id AND sm.g1>sm.g2) )as gz1,
(SELECT ISNULL(sum(Distinct(sm.g2)),0) FROM Matches sm,Parts sp where sp.champid=p.champid AND (sm.partsid2=p.id AND sm.g1<sm.g2) )as gz2,
(SELECT ISNULL(sum(Distinct(sm.g1)),0) FROM Matches sm,Parts sp where sp.champid=p.champid AND (sm.partsid1=p.id AND sm.g1<sm.g2) )as gp1,
(SELECT ISNULL(sum(Distinct(sm.g2)),0) FROM Matches sm,Parts sp where sp.champid=p.champid AND (sm.partsid2=p.id AND sm.g1>sm.g2) )as gp2
FROM Teams t left join Parts p on(t.teamid=p.teamid) where p.champid like 'ea716e0e-dff2-46f7-a6c2-49d40bced634' ORDER BY game



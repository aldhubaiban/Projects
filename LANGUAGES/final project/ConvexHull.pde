import java.lang.Math;

Polygon ConvexHullGiftWrapped( ArrayList<Point> points ) {
  Polygon cHull = new Polygon();


  if (points.size()>2) {   
    Point bottommost=points.get(0);
    int i=0;
    for (  i=0; i<points.size(); i++ )
    {
      if (bottommost.y()>points.get(i).y())
      {
        bottommost=points.get(i);
      }
    }
    // good 
    cHull.addPoint(bottommost);
    Point next_point=bottommost;
     PVector v1 = new PVector(1, 0);
   while(true)
  {
     next_point=nextPointFunc(bottommost,v1);
    if(next_point==cHull.p.get(0)){break;}
  else
  {
    cHull.addPoint(next_point);
    v1= new PVector (next_point.x() - bottommost.x(), next_point.y() - bottommost.y());
    bottommost=next_point;
  }
  
  }


  }
  return cHull;
}

Point nextPointFunc(Point curentPoint,PVector v1) {
    float angle_between=10;
    Point nextPoint=null;
    for (Point point:points)
  {
        if (point!=curentPoint)
      {
        PVector v2=new PVector(point.x()-curentPoint.x(),point.y()-curentPoint.y());
        if(PVector.angleBetween(v2,v1) <angle_between)
      {
       nextPoint=point;
      angle_between= PVector.angleBetween(v1, v2);
      }
      }
  
  }

  return nextPoint;
}

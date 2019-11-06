class Polygon {
  
   ArrayList<Point> p     = new ArrayList<Point>();
   ArrayList<Edge>  bdry = new ArrayList<Edge>();
     
   Polygon( ){  }
   
   
   boolean isClosed(){ return p.size()>=3; }
   
   
   // defintoion of Simple Polygon no intersect itself and no holes 
   boolean isSimple(){
     // TODO: Check the boundary to see if it is simple or not
     if(!isClosed()){return false;}
 
    
       
     ArrayList<Edge> bdry = getBoundary();
     int counter=0;
     
     for(int i=0; i<bdry.size();i++)
   {
     Edge E0=bdry.get(i);
     for(int j=i+1;j<bdry.size();j++)
     {
       Edge E1=bdry.get(j);
       
       if(E0.intersectionTest(E1))
     {
       counter++;
     
     }
    
     }
     
     
   }


//print("counter "+counter);
//print("\n");
//print(" bdry size "+bdry.size());
//print("\n");
if( counter%bdry.size()==0)
{
return true;
}
     
     return false;
   }
   
   
   boolean pointInPolygon( Point p ){
     // TODO: Check if the point p is inside of the 
     ArrayList<Edge> bdry = getBoundary();
     Point right_of_p=new Point (800,p.y()); // 800 means to most right of canvas by assumung canvas size is 800
     Edge etr=new Edge (right_of_p,p); // etr is edge to right something like this -->
     int counter=0;
     for(int i=0;i<bdry.size();i++)
     {
       
       if (etr.intersectionTest(bdry.get(i)))
     {
       counter++;
     }
     
     }
    //print("\n");
    //print(counter);
    //print("\n");
     if (counter%2==0)
     {
       return false;
     }

     return true;
   }
   
   
   ArrayList<Edge> getDiagonals(){
     // TODO: Determine which of the potential diagonals are actually diagonals
     ArrayList<Edge> bdry = getBoundary();
     ArrayList<Edge> diag = getPotentialDiagonals();
     ArrayList<Edge> ret  = new ArrayList<Edge>();
     int counter=0;
     
     for (int i=0;i<diag.size();i++)
   {
    
     
     for(int j=0; j<bdry.size();j++)
     {
     
       if(diag.get(i).intersectionTest(bdry.get(j))) // it need to intersect no more than 4 times to be diag 
     {
       counter++;
     }
  
       
     }
     
           if(counter<5 && pointInPolygon(diag.get(i).midpoint()))  // intersect less than 5 times and midpint is inside the diag then its polygon 
  {
        ret.add(diag.get(i));
  }
     
  counter=0;
        
    
     
   }
     
     
     
    
     return ret;
   }
   
   
   boolean ccw(){
     // TODO: Determine if the polygon is oriented in a counterclockwise fashion
     if( !isClosed() ) return false;
     if( !isSimple() ) return false;
     
        int sum=0;
     for(int i=1; i<p.size()-1;i++)
   {
     Point p1;
     Point p0=p.get(i);
     
      p1=p.get(i+1);
   
      
      sum+=(  (p1.x()-p0.x())*(p1.y()+p0.y())    );
   
   }
   
   if(sum<0){return true;}
     
     return false;
   }
   
   
   boolean cw(){
     // TODO: Determine if the polygon is oriented in a clockwise fashion
     if( !isClosed() ) return false;
     if( !isSimple() ) return false;
     
        int sum=0;
     for(int i=1; i<p.size()-1;i++)
   {
     Point p1;
     Point p0=p.get(i);
     
      p1=p.get(i+1);
   
      
      sum+=(  (p1.x()-p0.x())*(p1.y()+p0.y())    );
   
   }
   
   if(sum>0){return true;}
     
     return false;
   }
      
   
   
   
   ArrayList<Edge> getBoundary(){
     return bdry;
   }


   ArrayList<Edge> getPotentialDiagonals(){
     ArrayList<Edge> ret = new ArrayList<Edge>();
     int N = p.size();
     for(int i = 0; i < N; i++ ){
       int M = (i==0)?(N-1):(N);
       for(int j = i+2; j < M; j++ ){
         ret.add( new Edge( p.get(i), p.get(j) ) );
       }
     }
     return ret;
   }
   

   void draw(){
    // println( bdry.size() );
     for( Edge e : bdry ){
       e.draw();
     }
   }
   
   
   void addPoint( Point _p ){ 
     p.add( _p );
     if( p.size() == 2 ){
       bdry.add( new Edge( p.get(0), p.get(1) ) );
       bdry.add( new Edge( p.get(1), p.get(0) ) );
     }
     if( p.size() > 2 ){
       bdry.set( bdry.size()-1, new Edge( p.get(p.size()-2), p.get(p.size()-1) ) );
       bdry.add( new Edge( p.get(p.size()-1), p.get(0) ) );
     }
   }

}

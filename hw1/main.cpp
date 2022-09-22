#include <iostream>
#include "BMP.h"
#include <cmath>

using namespace std;

int main() {

    BMP bmpNew(1600,800,false);
    bmpNew.fill_region(0, 0, 1600, 800, 0, 0, 0, 0);
    
  int long_radius=768;
  int short_radius=384;
  int center_x = 800; 
  int center_y=400;
  
  float dx, dy, d1, d2, x, y;
  //ellipse starts from (0,b)
	x=0;
	y=short_radius;

  //Region 1
  //Decision parameter 
  d1=(short_radius * short_radius)+(0.25 * long_radius * long_radius)-(long_radius * long_radius * short_radius);
  //slope m=dy/dx
	dx=2*x*short_radius*short_radius;
	dy=2*y*long_radius*long_radius;

	while (dy>dx)//slope is less than -1
	{
    bmpNew.set_pixel(x + center_x, y + center_y, 255, 255, 255, 0);
    // bmpNew.set_pixel(x + center_x+1, y + center_y+1, 255, 255, 255, 0);
    // bmpNew.set_pixel(x + center_x+2, y + center_y+1, 255, 255, 255, 0);
    // bmpNew.set_pixel(x + center_x+3, y + center_y+1, 255, 255, 255, 0);
    // bmpNew.set_pixel(x + center_x+4, y + center_y+1, 255, 255, 255, 0);
    // bmpNew.set_pixel(x + center_x+5, y + center_y+1, 255, 255, 255, 0);
    bmpNew.set_pixel(x + center_x, -y + center_y-1, 255, 255, 255, 0);
   
		//checking for next coordinates
		if (d1 < 0)
		{
      //cout<<"part 1   "<< d1<<endl;
			x++;
			dx=dx+(2*short_radius*short_radius);
			d1=d1+dx+(short_radius*short_radius);
      
		}
		else
		{
      //cout<<"part 2   "<< d1<<endl;
			x++;
			y--;
			dx=dx+(2*short_radius*short_radius);
			dy=dy-(2*long_radius*long_radius);
			d1=d1+dx-dy+(short_radius*short_radius);
		}
	}
  
	//Region 2
  //Decision parameter //NOT WORK CORRECTLY
  /*d2=short_radius*short_radius*(x+0.5)*(x+0.5)+long_radius*long_radius*(y-1)*(y-1)-(long_radius*long_radius*short_radius*short_radius);
	while (y > 0)//plotting the rest of region 1
	{
    y--;
    dy=dy-(2*long_radius*long_radius);
    if (d2 >= 0){
      //cout<<"part 1    "<<d2<<endl;
      d2=d2+(long_radius*long_radius)-dy;
      //cout<<d2<<endl;
    }
    else{
      cout<<"part 2    "<<d2<<endl;
      x++;
			dx=dx+(2*short_radius*short_radius);
      d2=d2+(long_radius*long_radius)-dy+dx;
    }
    bmpNew.set_pixel(x + center_x, y + center_y, 255, 255, 255, 0);
    //cout << x + center_x << " , " << y + center_y << endl;
    bmpNew.set_pixel(x + center_x, -y + center_y, 255, 255, 255, 0);
	}*/
  
  
  for(int i=x+center_x;i<=long_radius+center_x;i++){
    //cout<<"i "<<i<<" y "<<y<<endl;
    for(int t=y+center_y;t>0;t--){
      //cout<<" "<<y<<endl;
       if((float(float(i-800)/12)*float(float(i-800)/12)+float(float(t-400)/6)*float(float(t-400)/6)<=(64+0.1)*(64+0.1))&&
         (float(float(i-800)/12)*float(float(i-800)/12)+float(float(t-400)/6)*float(float(t-400)/6)>=(64-0.1)*(64-0.1))){
         bmpNew.set_pixel(i, t, 255, 255, 255, 0);
         //cout<<"i = "<<i<<" t = "<<t<<endl;
         //cout<<float(float(i-800)/12)*float(float(i-800)/12)+float(float(t-400)/6)*float(float(t-400)/6)<<endl;
       }
    }
  }
  
  bmpNew.write("output.bmp");


}

//reference: https://www.geeksforgeeks.org/midpoint-ellipse-drawing-algorithm/

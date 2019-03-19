#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

/* Trying to fit smaller circles within a larger rectangle .*/
int smallerCircles_within_largerRectangle(ofstream& file,float rect_width,float rect_height,float radius){

	int i,j;
	int count=0; /* counter for count of circles.*/

	file << "<rect width=\"" << rect_width << "\"" << " height=\"" << rect_height << "\"" << " fill=\"red\"/>\n" ;

	for(i=radius;i<=rect_width-radius;i += 2*radius){ /* for x-axis the condition that the circle does not overflow the rectangle*/

		for(j=radius;j<=rect_height-radius;j += 2*radius){ /* for y-axis the condition that the circle does not overflow the rectangle*/
			count++;
			file << "<circle cx=\"" << i << "\"" << " cy=\"" << j << "\"" << " r=\"" << radius << "\" fill=\"green\"/>\n" ;
		}

	}
	return count;

}

/* Trying to fit smaller rectangles within a larger rectangle .*/
int smallerRectangles_within_largerRectangle(ofstream& file,float rect1_width,float rect1_height,float rect2_width,float rect2_height){

	int i,j;
	int count=0;

	file << "<rect width=\"" << rect1_width << "\"" << " height=\"" << rect1_height << "\"" << " fill=\"red\"/>\n" ;

	/*Using this loop for horizontal rectangle.*/
	for(i=0;i<=rect1_width; i += rect2_width){	

		if(!(i+rect2_width > rect1_width)){	/* for x-axis the condition that the rectangle does not overflow the rectangle*/

			for(j=0;j<=rect1_height; j += rect2_height){
				
				if(!(j+rect2_height>rect1_height)){
					count++;
					file << "<rect x=\"" << i << "\"" << " y=\"" << j << "\"" << " width=\"" << rect2_width << "\"" << " height=\"" << rect2_height << "\"" << " style=\"fill:green \"/>\n" ;
				}
					
			}
		}
	}
	i -= rect2_width;

	/*Using this loop for vertical rectangle.*/

	for(i;i<=rect1_width;i += rect2_height){
		
		if(rect1_width-i >= rect2_height){	/* for x-axis the condition that the rectangle does not overflow the rectangle*/

			for(j=0;j<=rect1_height; j += rect2_width){
				
				if(!(j+rect2_width>rect1_height)){	/* for y-axis the condition that the rectangle does not overflow the rectangle*/
					count++;
					file << "<rect x=\"" << i << "\"" << " y=\"" << j << "\"" << " width=\"" << rect2_height << "\"" << " height=\"" << rect2_width << "\"" << " style=\"fill:green \"/>\n" ;
				}
					
			}
		}
	}
	return count;
}

/* Trying to fit smaller triangles within a larger rectangle .*/
int smallerTriangles_within_largerRectangle(ofstream& file,float triangle_edge,float rect_width,float rect_height){

	float i,j;
	int count=0;
	float innerheight;
	innerheight = (triangle_edge/2)*sqrt(3); /*height of triangle*/
	/*triangle points*/
	float point1X=0,point1Y=innerheight,point2X=triangle_edge/2,point2Y=0,point3X=triangle_edge,point3Y=innerheight;	
	float point12X=triangle_edge/2,point12Y=0,point22X=triangle_edge+triangle_edge/2,point22Y=0,point32X=triangle_edge,point32Y=innerheight;

	file << "<rect width=\"" << rect_width << "\"" << " height=\"" << rect_height << "\"" << " fill=\"red\"/>\n" ;

	/*Using this loop for flat triangles*/
	for(i=0;i<rect_width;i+=triangle_edge){
		if(!(i+triangle_edge > rect_width)){	/* for x-axis the condition that the triangle does not overflow the rectangle*/

			for(j=0;j<rect_height;j+=innerheight){
				if(!(j+innerheight > rect_height)){	/* for y-axis the condition that the triangle does not overflow the rectangle*/
					count++;
					file << "<polygon points=\"" << point1X+i << " " << point1Y+j << "," << point2X+i << " " << point2Y+j << "," << point3X+i << " " << point3Y+j << "\" fill=\"green\"/>\n" ;
				}
			}
		}
	}

	/*Using this loop for inverted triangles*/
	for(i=0;i<rect_width;i+=triangle_edge){
		if(!(i+triangle_edge+triangle_edge/2 > rect_width)){

			for(j=0;j<rect_height;j+=innerheight){
				if(!(j+innerheight > rect_height)){
					count++;
					file << "<polygon points=\"" << point12X+i << " " << point12Y+j << "," << point22X+i << " " << point22Y+j << "," << point32X+i << " " << point32Y+j << "\" fill=\"blue\"/>\n" ;
				}
			}
		}
	}

	return count;

}

/* Trying to fit smaller rectangles within a larger triangle .*/

int smallerRectangles_within_largerTriangle(ofstream& file,float triangle_edge,float rect_width,float rect_height){

	float i,j,k;
	int count=0;
	float innerheight;

	innerheight = (triangle_edge/2)*sqrt(3); /*Height of triangle.*/
	
	float a = rect_width/sqrt(3); /* Distance of small pieces.*/


	file << "<polygon points=\"" << 0 << " " << innerheight << "," << triangle_edge/2 << " " << 0 << "," << triangle_edge << " " << innerheight << "\" fill=\"red\"/>\n" ;
	

	for(i=rect_width/sqrt(3),j=innerheight-rect_width;i<=triangle_edge/2,j>=0;i += rect_width/sqrt(3),j-=rect_width){ /*Determining first position and starting the loop.*/

		for(k=i;k<=triangle_edge-a;k+=rect_height){
			if(!(k+rect_height > triangle_edge-a)){
				file << "<rect x=\"" << k << "\"" << " y=\"" << j << "\"" << " width=\"" << rect_height << "\"" << " height=\"" << rect_width << "\"" << " fill=\"green\"/>\n" ;
				count++;
				
			}
		}
		a = a +	rect_width/sqrt(3); /* We are carrying our position to upper line.*/
	}

	return count;

}

/* Trying to fit smaller triangles within a larger triangle .*/

int smallerTriangles_within_LargerTriangle(ofstream& file,float small_t_edge,float larger_t_edge){

	float i,j,k;
	int count=0;
	float Linnerheight,Sinnerheight;
	Linnerheight = (larger_t_edge/2)*sqrt(3);	/*Height of larger triangle .*/
	Sinnerheight = (small_t_edge/2)*sqrt(3);	/*Height of smaller triangle .*/
	float a = small_t_edge/2;
	float b = 0;
	float point1X=a,point1Y=Linnerheight-Sinnerheight,point2X=0,point2Y=Linnerheight,point3X=small_t_edge,point3Y=Linnerheight;	/*First position.*/
	

	file << "<polygon points=\"" << 0 << " " << Linnerheight << "," << larger_t_edge/2 << " " << 0 << "," << larger_t_edge << " " << Linnerheight << "\" fill=\"red\"/>\n" ;

	/*This loop for flat triangles.*/
	for(i=0;i<=larger_t_edge/2;i+=small_t_edge/2){

		for(j=0;j<larger_t_edge-b;j+=small_t_edge){

			if(!(j+small_t_edge > larger_t_edge-b)){	/* for y-axis the condition that the triangle does not overflow the larger triangle*/
				file << "<polygon points=\"" << point1X+j << " " << point1Y << "," << point2X+j << " " << point2Y << "," << point3X+j << " " << point3Y << "\" fill=\"green\"/>\n" ;
				count++;
			}
				
		}

		point1X += a;
		point1Y -= Sinnerheight;
		point2X += a;
		point2Y -= Sinnerheight;
		point3X += a;
		point3Y -= Sinnerheight;
		b += 2*a ;
	}

	point1X=a,point1Y=Linnerheight-Sinnerheight,point2X=2*a,point2Y=Linnerheight,point3X=3*a,point3Y=Linnerheight-Sinnerheight;	/*Preparing the position of inverted triangles.*/
	b=2*a;

	/*This loop for inverted triangles.*/
	for(i=0;i<=larger_t_edge/2;i+=small_t_edge/2){

		for(j=0;j<larger_t_edge-b;j+=small_t_edge){

			if(!(j+small_t_edge > larger_t_edge-b)){	/* for y-axis the condition that the triangle does not overflow the larger triangle*/
				file << "<polygon points=\"" << point1X+j << " " << point1Y << "," << point2X+j << " " << point2Y << "," << point3X+j << " " << point3Y << "\" fill=\"blue\"/>\n" ;
				count++;
			}
				
		}

		point1X += a;
		point1Y -= Sinnerheight;
		point2X += a;
		point2Y -= Sinnerheight;
		point3X += a;
		point3Y -= Sinnerheight;
		b += 2*a ;
	}

	return count;	/*Returning count of triangles.*/

}

/* Trying to fit smaller circles within a larger triangle .*/

int smallerCircles_within_largerTriangle(ofstream& file,float radius,float t_edge){
	
	float i,j;
	int count=0;
	float innerheight = t_edge*sqrt(3)/2;	/*Height of triangle.*/
	float a = radius*sqrt(3); /*Distance of small pieces*/
	int b=0;

	file << "<polygon points=\"" << 0 << " " << innerheight << "," << t_edge/2 << " " << 0 << "," << t_edge << " " << innerheight << "\" fill=\"red\"/>\n" ;

	for(j=innerheight-radius;j>=0+radius-innerheight;j-=a){	/* for y-axis the condition that the circle does not overflow the larger triangle*/
		
		for(i=a+b*radius;i<=t_edge-a-b*radius;i+=2*radius){	/* for x-axis the condition that the circle does not overflow the larger triangle*/

			file << "<circle cx=\"" << i << "\"" << " cy=\"" << j << "\"" << " r=\"" << radius << "\" fill=\"green\"/>\n" ;
			count++;
		}

		b+=1;
	}

	return count;

}

int smallerCircles_within_LargerCircle(ofstream& file,float large_radius,float small_radius){
	float i,j;
	int count=0;
	
	float formula=0;

	file << "<circle cx=\"" << large_radius << "\"" << " cy=\"" << large_radius << "\"" << " r=\"" << large_radius << "\" fill=\"red\"/>\n" ;
	file << "<circle cx=\"" << large_radius << "\"" << " cy=\"" << small_radius << "\"" << " r=\"" << small_radius << "\" fill=\"green\"/>\n" ;
	count++;

	for(j=3*small_radius;j<=2*large_radius-2*small_radius;j+=2*small_radius){
		i = large_radius;
		formula = 0;
		do{
			file << "<circle cx=\"" << i << "\"" << " cy=\"" << j << "\"" << " r=\"" << small_radius << "\" fill=\"green\"/>\n" ;
			count++;
			i+=2*small_radius;
			formula = sqrt(pow(large_radius-i,2)+pow(large_radius-j,2));
		}
		while(formula<=large_radius-small_radius);
	}

	for(j=3*small_radius;j<=2*large_radius-2*small_radius;j+=2*small_radius){
		i = large_radius-2*small_radius;
		formula = 0;
		while(formula<=large_radius-small_radius){
			file << "<circle cx=\"" << i << "\"" << " cy=\"" << j << "\"" << " r=\"" << small_radius << "\" fill=\"green\"/>\n" ;
			count++;
			i-=2*small_radius;
			formula = sqrt(pow(large_radius-i,2)+pow(large_radius-j,2));
		}
		
	}
	
	return count;
}

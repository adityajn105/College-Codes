import java.util.Scanner;

class Shape{
	protected double x,y;
	
	public Shape(){
		this.x=0.0;
		this.y=0.0;
	}
	public void getData(double x,double y){
		this.x=x;
		this.y=y;
	}
	public void area(){};
}

class Rectangle extends Shape{
	private double area;
	public Rectangle(){
		area=0.0;
	}
	public void area(){
		area= super.x*super.y;
	}
	public String toString(){
		return "Area of Rectangle: "+area;
	}
}

class Triangle extends Shape{
	private double area;
	public Triangle(){
		area=0.0;
	}
	public void area(){
		area= 0.5*super.x*super.y;
	}
	public String toString(){
		return "Area of triangle: "+area;
	}
}


public class test {
	public static void main(String[] args){
		Scanner reader=new Scanner(System.in);
		while(true)
		{
			System.out.print("1.Rectangle\n2.Triangle\n3.Exit\nEnter choice:");
			int ch=reader.nextInt();
			boolean loop=false;
			switch(ch){
				case 1:{
					System.out.print("Enter Length and Breadth :");
					double len=reader.nextDouble();
					double bre=reader.nextDouble();
					Shape s1=new Rectangle();
					s1.getData(len,bre);
					s1.area();
					System.out.println(s1);
					continue;
				}
				case 2:{
					System.out.print("Enter Base and Height :");
					double base=reader.nextDouble();
					double height=reader.nextDouble();
					Shape s2=new Triangle();
					s2.getData(height, base);
					s2.area();
					System.out.println(s2);
					continue;
				}
				default:loop=true;break;
			}
			if(loop)break;
		}
		reader.close();
		
	}

}

package watertank;
import java.io.*;
import java.util.*;

class WaterTank {
	public static void main(String[] args) throws Exception{
//		 Dot (StringBuilder nodeIndex,int t,double waterLever,
//					double pro,int k1State,int k2State,int k3State,boolean isk1OK,
//					boolean isk2OK,boolean isk3OK,StringBuilder attr)
		
		SubDot dot=new SubDot(new StringBuilder("0"),0,0.0,1.0,1,0,1,
				true,true,true,new StringBuilder("root"));
		dot.writeDotForever(dot);
		for(dot.t=0; dot.t<20;) {
//			dot.writeDotTemp(dot);
//			dot.writeDotForever(dot);
//			dot.readDotTemp(dot);
			dot.produceNewDot(dot);
//			SubDot dot1=(SubDot)dot.list.removeFirst();
		}

		}
}

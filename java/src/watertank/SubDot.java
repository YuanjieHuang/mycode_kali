package watertank;
import java.io.*;
import java.util.*;

class SubDot extends Dot {
	public SubDot (StringBuilder nodeIndex,int t,double waterLever,
			double pro,int k1State,int k2State,int k3State,
			boolean isk1OK,
			boolean isk2OK,boolean isk3OK,StringBuilder attr){
		super (nodeIndex, t, waterLever,
				 pro, k1State, k2State, k3State,isk1OK,
				 isk2OK, isk3OK, attr);}
	
	public  void writeDotTemp(Dot dot) throws IOException, ClassNotFoundException
	{
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("ReadFrom"));
		out.writeObject(dot.nodeIndex);
		out.writeInt(dot.t);
		out.writeDouble(dot.waterLever);
		out.writeDouble(dot.pro);
		out.writeInt(dot.k1State);
		out.writeInt(dot.k2State);
		out.writeInt(dot.k3State);
		out.writeBoolean(dot.isk1OK);
		out.writeBoolean(dot.isk2OK);
		out.writeBoolean(dot.isk3OK);
		out.writeObject(dot.attr);

		System.out.print("\t"+nodeIndex);
//		System.out.println(waterLever)
//		System.out.println(pro);
		System.out.print("\t"+k1State);
		System.out.print("\t"+k2State);
		System.out.println("\t"+k3State);
		
		out.flush();
		out.close();
	}

	// 读取节点数据至输入流。
	public   void readDotTemp(Dot dot) throws IOException, ClassNotFoundException {
		ObjectInputStream ois = new ObjectInputStream(new FileInputStream("ReadFrom"));
		nodeIndex = (StringBuilder) ois.readObject();
		t = ois.readInt();
		waterLever = ois.readDouble();
		pro = ois.readDouble();
		k1State = ois.readInt();
		k2State = ois.readInt();
		k3State = ois.readInt();
		isk1OK = ois.readBoolean();
		isk2OK = ois.readBoolean();
		isk3OK = ois.readBoolean();
		attr = (StringBuilder) ois.readObject();
//		list.removeFirst();

		System.out.print("\t"+nodeIndex);
		System.out.println("\t"+waterLever);
		System.out.println("\t"+pro);
		System.out.print("\t"+k1State);
		System.out.print("\t"+k2State);
		System.out.println("\t"+k3State);
		ois.close();
	}

	public  void writeDotForever(Dot dot) throws IOException, ClassNotFoundException
	// ClassNotFoundException, EOFException,NullPointerException
	{
		PrintWriter out2 = new PrintWriter(new FileOutputStream("SaveAllNodePah.txt",true), true);
		out2.println("nodeIndex=" + dot.nodeIndex);
		out2.println("t=" + dot.t);
		out2.println("waterLever=" + dot.waterLever);
		out2.println("pro=" + dot.pro);
		out2.println("k1State=" + dot.k1State);
		out2.println("k2State=" + dot.k2State);
		out2.println("k3Stat=" + dot.k3State);
		out2.println("isk1OK=" + dot.isk1OK);
		out2.println("isk2OK=" + dot.isk2OK);
		out2.println("isk3OK=" + dot.isk3OK);
		out2.println("attr=" + dot.attr);
		out2.close();
	}
	public Dot produceNewDot(Dot dot) throws IOException, ClassNotFoundException{
		
		nodeIndex=dot.runNodeIndex(dot.nodeIndex,dot.isk1OK,dot.isk2OK,dot.isk3OK);
		t=runTime(dot.t);
		waterLever=runWaterLever(dot.waterLever);
		pro=runPro(dot.pro);
		k1State=runk1State(dot.isk1OK,dot.waterLever);
		k2State=runk2State(dot.isk2OK,dot.waterLever);
		k3State=runk3State(dot.isk3OK,dot.waterLever);
		isk1OK=runisk1OK(dot.isk1OK);
		isk2OK=runisk2OK(dot.isk2OK);
		isk3OK=runisk3OK(dot.isk3OK);
		attr=runAttr(dot.attr);
		
		writeDotTemp(dot);
		listTemp.addFirst(dot);
		writeDotForever(dot);
//		Map<StringBuilder,Dot> map=new HashMap<StringBuilder,Dot>();
//		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("ReadFrom",true));
		
		return dot;
	}
	LinkedList listTemp=new LinkedList();
	LinkedList listTempSave=new LinkedList();

}
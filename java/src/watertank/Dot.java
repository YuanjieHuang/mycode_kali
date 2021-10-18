package watertank;

import java.io.*;
import java.util.*;

class Dot {
	public Dot() {}
	public  Dot (StringBuilder nodeIndex,int t,double waterLever,
			double pro,int k1State,int k2State,int k3State,boolean isk1OK,
			boolean isk2OK,boolean isk3OK,StringBuilder attr) {
		
		this.nodeIndex=nodeIndex;
		this.t=t;
		this.waterLever=waterLever;
		this.pro=pro;
		this.k1State=k1State;
		this.k2State=k2State;
		this.k3State=k3State;
		this.attr=attr;
		this.isk1OK=isk1OK;
		this.isk2OK=isk2OK;
		this.isk3OK=isk3OK;
//		this.tag=tag;
		
		
	}

	

	StringBuilder nodeIndex = new StringBuilder();// 给该节点指定唯一的索引号
	int t;// 记录该节点的产生时间
	double waterLever;// 记录该节点的液面高度
	double pro;// 记录此节点的概率
	int k1State;// 表示阀门1的打开关闭状态，0（关闭），1（打开）
	int k2State;// 表示阀门2的打开关闭状态，0（关闭），1（打开）
	int k3State;// 表示阀门3的打开关闭状态，0（关闭），1（打开）
	boolean isk1OK;// 记录信号接收器1是否失效，False(失效),True(正常)
	boolean isk2OK;// 记录信号接收器2是否失效，False(失效),True(正常)
	boolean isk3OK;// 记录信号接收器3是否失效，False(失效),True(正常)
	StringBuilder attr = new StringBuilder();// 节点属性，root表示根节点，node表示叶节点，Gleaf表示事故节点，Wleaf表示非事故节点
	boolean tag; // (waterLever>3||waterLever<-3,
	// k1State=0&&k2State=0&&k3State=0,isk1OK=false&&isk2OK=false&&isk3OK=false);//作为关键状态搜索标记
	
	
	public StringBuilder runNodeIndex(StringBuilder nodeIndex,boolean isk1OK,boolean isk2OK,boolean isk3OK) 
			 {
		
		String str=nodeIndex.toString().replaceAll("0","");
		int num;
		if(str.isEmpty()) { num=0;}
		else {
		 num=Integer.parseInt(str);}
		
		switch (num) {
		
			case 0://节点编号只有0
			if (!isk1OK) {
				nodeIndex = nodeIndex.append("1");
	
			} else if (!isk2OK) {
				nodeIndex = nodeIndex.append("2");
	
			} else if (!isk3OK) {
				nodeIndex = nodeIndex.append("3");
	
			} else {
				nodeIndex = nodeIndex.append("0");
	
			}
			return nodeIndex;
			
			case 1://节点编号含有1
			if (!isk2OK) {
				nodeIndex = nodeIndex.append("2");
	
			} else if (!isk3OK) {
				nodeIndex = nodeIndex.append("3");
			} else {
				nodeIndex = nodeIndex.append("0");}
				return nodeIndex;
				
			case 2://含2
			if (!isk1OK) {
				nodeIndex = nodeIndex.append("1");
	
			} else if (!isk3OK) {
				nodeIndex = nodeIndex.append("3");
			} else {
				nodeIndex = nodeIndex.append("0");}
				return nodeIndex;
				
			case 3://含3
			if (!isk1OK) {
				nodeIndex = nodeIndex.append("1");
	
			} else if (!isk2OK) {
				nodeIndex = nodeIndex.append("2");
	
			} else {
				nodeIndex = nodeIndex.append("0");
	
			}
			return nodeIndex;
			
			case 12://含12
			if (!isk3OK) {
				nodeIndex = nodeIndex.append("3");
	
			} else {
				nodeIndex = nodeIndex.append("0");
	
			}
			return nodeIndex;
			
			case 13://含13
				if (!isk2OK) {
					nodeIndex = nodeIndex.append("2");
				} else {
					nodeIndex = nodeIndex.append("0");
				}
				return nodeIndex;
				
			case 23://含23
				if (!isk1OK) {
					nodeIndex = nodeIndex.append("1");
		
				} else {
					nodeIndex = nodeIndex.append("0");
		
				}
				return nodeIndex;
				
			case 123://含123
				return nodeIndex;
				default :
					return nodeIndex;
		}
	}

	public int runTime(int t) {
		t++;
		return t;

	}

	public double runWaterLever(double waterLever) {
		waterLever = waterLever+(1*k1State+0.5*k2State-1.2*k3State);
		return waterLever;

	}
	public void waterLeverContorl(double waterLever) {
		if(-1<=waterLever&&waterLever<=1) {
			}
			else if(waterLever>1&&waterLever<=3) {
				if(isk1OK) {k1State=0;}
				if(isk2OK) {k2State=0;}
				if(isk3OK) {k3State=1;}
			}
			else if(waterLever<-1&&waterLever>=-3) {
				if(isk1OK) {k1State=1;}
				if(isk2OK) {k2State=1;}
				if(isk3OK) {k3State=0;}
			}
			else {
				System.out.println("水位溢出或干涸");
				System.exit(0);}
	}

	public double runPro(double pro) {
		pro = pro * 0.01 * 0.99 * 0.99;
		return pro;
	}

	public int runk1State(boolean isk1OK,double waterLever) {
		if (-1<=waterLever&&waterLever<=1) {
					if (isk1OK) {
					k1State = 1;
				}
				else {
					k1State = 0;
				}
				
			}
		else {waterLeverContorl(waterLever);}
		return k1State;
	}
	
	 public Map<StringBuilder, Integer> test1(int[] arr) {
	        Map<StringBuilder, Integer> map = new HashMap<StringBuilder, Integer>();

	        int max = Integer.MIN_VALUE;
	        int min = Integer.MAX_VALUE;
	        for (int i = 0; i < arr.length; i++) {
	            if (arr[i] > max) {
	                max = arr[i];
	            }
	            if (arr[i] < min) {
	                min = arr[i];
	            }
	        }

	        map.put("max", max);
	        map.put("min", min);

	        return map;
	    }
	
	public int runk2State(boolean isk2OK,double waterLever) {
		if (-1<=waterLever&&waterLever<=1) {
			if (isk2OK) {
				k2State = 0;
			} else {
				k2State = 1;
			}
		}
		else {waterLeverContorl(waterLever);}
		
		return k2State;
	}
	

	public int runk3State(boolean isk3OK,double waterLever) {
		if (-1<=waterLever&&waterLever<=1) {
				if (isk3OK) {
					k3State = 1;
				} else {
					k3State = 0;
				}
		}
		else {waterLeverContorl(waterLever);}
				return k3State;
	}

	public boolean runisk1OK(boolean isk1OK) {
		
		if (!(isk1OK)) {
			return isk1OK=isk1OK;}
		else {
			if(Math.random()<0.01) {
				return isk1OK=false;
				 }
			else {
				isk1OK=isk1OK;}
		 }
		return isk1OK;

	}
//	public boolean[][] runisok(boolean isk1OK,boolean isk2OK,boolean isk3OK) {
//		boolean[][] arr=new boolean[3][3];
//		for(int i=0;i<3;i++) {
//			
//		}
//		
//		
//		return arr;
//				}

	public boolean runisk2OK(boolean isk2OK) {
		if (!(isk2OK)) {
			return isk2OK=isk2OK;}
		else {
			if(Math.random()<0.01) {
				return isk2OK=false;
				 }
			else {
				isk2OK=isk2OK;}
		 }
		return isk2OK;

	}

	public boolean runisk3OK(boolean isk3OK) {
		if (!(isk3OK)) {
			return isk3OK=isk3OK;
			}
		else {
			if (Math.random() < 0.01) {
				return isk3OK=false;
				 }
			else {
				isk3OK=isk3OK;}
		 }
		return isk3OK;

	}

	public StringBuilder runAttr(StringBuilder attr) {
		// attr.toString();
		// String nodeIndex=nodeIndex.toString();
		if (nodeIndex.equals("0")) {
			attr.append("root");
		} else if (this.waterLever > 3 || this.waterLever < -3
				|| (this.k1State == 0 && this.k2State == 0 && this.k3State == 0)
						&& (this.isk3OK == false && this.isk2OK == false && this.isk3OK == false)) {
			attr.replace(0, attr.length() - 1, "Gleaf");

		}
		// exist problem
		else if (!(this.waterLever > 3 || this.waterLever < -3
				|| (this.k1State == 0 && this.k2State == 0 && this.k3State == 0)
						&& (this.isk3OK == false && this.isk2OK == false && this.isk3OK == false))) {
			attr.replace(0, attr.length() - 1, "Wleaf");
		} else {
			attr.replace(0, attr.length() - 1, "node");
		}
		return attr;
	}

	public boolean runTag() {
		if (this.waterLever > 3 || this.waterLever < -3 || (this.k1State == 0 && this.k2State == 0 && this.k3State == 0)
				&& (this.isk3OK == false && this.isk2OK == false && this.isk3OK == false))
			this.tag = true;
		else {
			this.tag = false;
		}
		return this.tag;
	}


}

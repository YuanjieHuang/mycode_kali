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

	

	StringBuilder nodeIndex = new StringBuilder();// ���ýڵ�ָ��Ψһ��������
	int t;// ��¼�ýڵ�Ĳ���ʱ��
	double waterLever;// ��¼�ýڵ��Һ��߶�
	double pro;// ��¼�˽ڵ�ĸ���
	int k1State;// ��ʾ����1�Ĵ򿪹ر�״̬��0���رգ���1���򿪣�
	int k2State;// ��ʾ����2�Ĵ򿪹ر�״̬��0���رգ���1���򿪣�
	int k3State;// ��ʾ����3�Ĵ򿪹ر�״̬��0���رգ���1���򿪣�
	boolean isk1OK;// ��¼�źŽ�����1�Ƿ�ʧЧ��False(ʧЧ),True(����)
	boolean isk2OK;// ��¼�źŽ�����2�Ƿ�ʧЧ��False(ʧЧ),True(����)
	boolean isk3OK;// ��¼�źŽ�����3�Ƿ�ʧЧ��False(ʧЧ),True(����)
	StringBuilder attr = new StringBuilder();// �ڵ����ԣ�root��ʾ���ڵ㣬node��ʾҶ�ڵ㣬Gleaf��ʾ�¹ʽڵ㣬Wleaf��ʾ���¹ʽڵ�
	boolean tag; // (waterLever>3||waterLever<-3,
	// k1State=0&&k2State=0&&k3State=0,isk1OK=false&&isk2OK=false&&isk3OK=false);//��Ϊ�ؼ�״̬�������
	
	
	public StringBuilder runNodeIndex(StringBuilder nodeIndex,boolean isk1OK,boolean isk2OK,boolean isk3OK) 
			 {
		
		String str=nodeIndex.toString().replaceAll("0","");
		int num;
		if(str.isEmpty()) { num=0;}
		else {
		 num=Integer.parseInt(str);}
		
		switch (num) {
		
			case 0://�ڵ���ֻ��0
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
			
			case 1://�ڵ��ź���1
			if (!isk2OK) {
				nodeIndex = nodeIndex.append("2");
	
			} else if (!isk3OK) {
				nodeIndex = nodeIndex.append("3");
			} else {
				nodeIndex = nodeIndex.append("0");}
				return nodeIndex;
				
			case 2://��2
			if (!isk1OK) {
				nodeIndex = nodeIndex.append("1");
	
			} else if (!isk3OK) {
				nodeIndex = nodeIndex.append("3");
			} else {
				nodeIndex = nodeIndex.append("0");}
				return nodeIndex;
				
			case 3://��3
			if (!isk1OK) {
				nodeIndex = nodeIndex.append("1");
	
			} else if (!isk2OK) {
				nodeIndex = nodeIndex.append("2");
	
			} else {
				nodeIndex = nodeIndex.append("0");
	
			}
			return nodeIndex;
			
			case 12://��12
			if (!isk3OK) {
				nodeIndex = nodeIndex.append("3");
	
			} else {
				nodeIndex = nodeIndex.append("0");
	
			}
			return nodeIndex;
			
			case 13://��13
				if (!isk2OK) {
					nodeIndex = nodeIndex.append("2");
				} else {
					nodeIndex = nodeIndex.append("0");
				}
				return nodeIndex;
				
			case 23://��23
				if (!isk1OK) {
					nodeIndex = nodeIndex.append("1");
		
				} else {
					nodeIndex = nodeIndex.append("0");
		
				}
				return nodeIndex;
				
			case 123://��123
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
				System.out.println("ˮλ�����ɺ�");
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

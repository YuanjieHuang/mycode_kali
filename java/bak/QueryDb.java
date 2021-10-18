package com.king.sqlCom;
import java.sql.*;  

	  
	public class QueryDb {  
	    public static void main(String[] args) {  
	        try {  
	            //1.调用Class.forName()方法加载驱动程序  
	            Class.forName("com.mysql.jdbc.Driver");  
	            System.out.println("成功加载MySQL驱动！");  
	              
	            String url= "jdbc:mysql://localhost:3306/rorm";//JDBC的URL   
	            String rootName = "root";  
	            String pwd ="root";  
	              
	            //2.建立连接  
	            //调用DriverManager对象的getConnection()方法，获得一个Connection对象  
	            Connection conn= null;  
	            //创建Statement对象  
	            Statement stmt  = null;  
	              
	            try {  
	                //建立数据库连接  
	                conn = DriverManager.getConnection(url,rootName,pwd);  
	                stmt  = conn.createStatement();//创建一个Statement对象  
	                System.out.println("成功连接到数据库~");  
	                  
	                //数据库查询语句  
	                String sql = "select * from et";//要执行的SQL  
	                  
	                /*在询数据表时，需要用到ResultSet接口，它类似于一个数据表，通过该接口的实例 
	                 * 可以获得检索结果集，以及对应数据表的接口信息。*/  
	                ResultSet rs = stmt.executeQuery(sql);//创建数据对象  
	                  
	                System.out.println("编 号"+"\t"+"NUM"+"\t"+"ID"+"\t"+"text");  
	                //遍历查询的结果集  
	                while (rs.next()) {  
	                    System.out.print(rs.getInt(1)+"\t");  
	                    System.out.print(rs.getString(2)+"\t");  
	                    System.out.print(rs.getString(3)+"\t");  
	                    System.out.print(rs.getString(4)+"\t");  
	                    System.out.println();  
	                }  
	                //关闭连接  
	                rs.close();  
	                stmt.close();  
	                conn.close();  
	            } catch (SQLException e) {  
	                e.printStackTrace();  
	            }             
	        } catch (ClassNotFoundException e) {  
	            e.printStackTrace();  
	        }  
	      
	    }  
	}  
package cn.lynu.service;

import com.lynu.service.A;

public class B {
    public static void main(String[] args) {
        System.out.println("jarB main方法调用");
        new A().sayHello();
    }
} 
package com.jiangwei;

import java.util.jar.Attributes.Name;

public class JniTest1 {
	
	public String name = "jiangwei";
	
	public native String changeFieldFromC();
	
	static{
		System.loadLibrary("jiangweijni");
	}
	
	public static void main(String[] args) {
		JniTest1 t = new JniTest1();
		System.out.println("name被修改之前："+t.name);
		String fixName = t.changeFieldFromC();
		System.out.println("getNameFromC："+fixName);
		System.out.println("name被修改之后："+t.name);
	}
}

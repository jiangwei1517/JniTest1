package com.jiangwei;

public class JniTest1 {

	public String name = "jiangwei";

	public static int age = 17;

	public native String changeFieldFromC();

	public native void changeAge();

	public native void callMethod();
	
	public native void callStaticMethod();

	static {
		System.loadLibrary("jiangweijni");
	}

	public static void main(String[] args) {
		JniTest1 t = new JniTest1();
		System.out.println("name被修改之前：" + t.name);
		String fixName = t.changeFieldFromC();
		System.out.println("getNameFromC：" + fixName);
		System.out.println("name被修改之后：" + t.name);

		System.out.println("age被修改之前：" + age);
		t.changeAge();
		System.out.println("age被修改之后：" + age);
		t.callMethod();
		
		t.callStaticMethod();
	}

	public int getInt(int i) {
		System.out.println("PRE I = " + i);
		i++;
		System.out.println("PRE I = " + i);
		return i;
	}
	
	public static String getMax(String max) {
		return max;
	}
}

package com.jiangwei;

import java.util.Date;

public class JniTest1 {

	public String name = "jiangwei";

	public static int age = 17;

	public native String changeFieldFromC();

	public native void changeAge();

	public native void callMethod();

	public native void callStaticMethod();

	public native long callConstructors();

	public native void callSuperMethod();

	public Man man = new Man();

	public native String getString(String name);

	public native int[] sortArray(int[] array);

	static {
		System.loadLibrary("jiangweijni");
	}

	public static void main(String[] args) {
		JniTest1 t = new JniTest1();
		System.out.println("name被修改之前：" + t.name);
		// 访问属性
		String fixName = t.changeFieldFromC();
		System.out.println("getNameFromC：" + fixName);
		System.out.println("name被修改之后：" + t.name);

		System.out.println("age被修改之前：" + age);
		// 访问静态属性
		t.changeAge();
		System.out.println("age被修改之后：" + age);
		// 访问方法
		t.callMethod();
		// 访问静态方法
		t.callStaticMethod();

		// 访问构造方法
		long time = t.callConstructors();
		System.out.println("time = " + time);

		// 访问父类的方法
		t.callSuperMethod();

		// 向C中传递字符串
		String newString = t.getString("小姜");
		System.out.println(newString);

		// C语言排序
		int[] sorts = { 1, 8, 4, 5, 88, 2 };
		int[] newSort = t.sortArray(sorts);
		for (int i = 0; i < newSort.length; i++) {
			System.out.println(newSort[i]);
		}
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

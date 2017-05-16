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

	public native void deleteLocalRef();

	public native String createGlobalRef(String str);

	public native String getGlobalRef();

	public native void deleteGlobalRef();

	public native String createWeakGlobalRef(String str);

	public native String getWeakGlobalRef();

	public native void deleteWeakGlobalRef();

	public native void throwException();

	public static native void init();

	public static String initA = "init";

	public static Man initMan = new Man();

	public native void cache();

	static {
		System.loadLibrary("jiangweijni");
		init();
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

		// 删除本地引用LocalRef
		t.deleteLocalRef();

		// 创建全局引用GlobalRef
		String newStr = t.createGlobalRef("zhouwenkai");
		System.out.println("创建全局new_str引用成功！new_str:" + newStr);

		// 删除全局引用
		t.deleteGlobalRef();

		// 获取全局引用
		String deleteStr = t.getGlobalRef();
		try {
			System.out.println(deleteStr);
		} catch (NullPointerException e) {
			System.out.println("删除全局引用成功！");
		}

		// 创建弱全局引用
		String weakStr = t.createWeakGlobalRef("weakStr");
		if (weakStr != null) {
			System.out.println("成功创建弱引用：" + weakStr);
		} else {
			System.out.println("失败创建弱引用：" + weakStr);
		}
		// 删除弱全局引用
		t.deleteWeakGlobalRef();
		// 获取弱全局引用
		try {
			String delWeak = t.getWeakGlobalRef();
			System.out.println(delWeak);
		} catch (Exception e) {
			System.out.println("删除弱引用成功!!");
		}
		// 抛出异常
		try {
			t.throwException();
		} catch (Exception e) {
			e.getMessage();
			System.out.println("异常抛出成功！" + e.getMessage());
		}

		// 初始化数据，启用缓存
		for (int i = 0; i < 100; i++) {
			t.cache();
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

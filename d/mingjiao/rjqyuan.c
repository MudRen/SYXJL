//RJQYUAN.C

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���߽��������Ĵ�Ժ��ȴ����������Ӱϡ�裬��������
�����˵Ĵ�������ȴ�����������̣��������ƺ��Ǵ���Զ�ĵ�
�´����ġ������ߣ���Ҫ������¥�ˡ�Ժ�����׿��������䳡��
��Լ����������������һ��������������������᳡����
LONG
	);

	set("exits", ([
		"west" : __DIR__"rjqmenlou1",
		"north" : __DIR__"rjqdating",
		"south" : __DIR__"rjqlwch",
		"east": __DIR__"rjqmen",
	]));
/*
        set("objects",(["/kungfu/class/mingjiao/lengqian":1,
        		"/kungfu/class/mingjiao/shuobude":1,
		        "/kungfu/class/mingjiao/zhangzhong":1,
		        "/kungfu/class/mingjiao/pengyingyu":1,
		        "/kungfu/class/mingjiao/zhoudian":1,
		        "/kungfu/class/mingjiao/yinyewang":1,
			]));
*/
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
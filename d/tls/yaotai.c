inherit ROOM;

void create()
{
        set("short", "�嶼��̨");
        set("long",@LONG
���ǳ���ǰ���µıؾ�֮·��������ȥ���ɼ�������̨ͤ¥���ģ��
�󣬹���������լ�����ƣ�������֮ʢ��ʤ����̨�����ӵ������ʤ��
����ɽ���¡�
LONG
        );
        set("outdoors","tianlongsi");
        set("exits", ([
                "westup": __DIR__"wuwujing", 
                "eastdown": __DIR__"shijie1", 
                "north":__DIR__"zhonglou",
                "south":__DIR__"gulou",                         
        ]));
        set("objects",([
                __DIR__"npc/xing-yun" : 1,
                __DIR__"npc/xiaoshami" : 1,
        ]));

        set("coor/x",-30);
	set("coor/y",-110);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-110);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-110);
	set("coor/z",20);
	set("coor/x",-30);
	set("coor/y",-110);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}


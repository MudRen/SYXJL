inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
���ǳ��������µıؾ�֮·��������ȥ���ɼ�����̨ͤ¥���ģ��
�󣬹���������լ�����ƣ�������֮ʢ��ʤ����̨�����ӵ������ʤ��
����ɽ���¡�
LONG
        );
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"jietan",    			
	        "west" : __DIR__"wulege",
		"east" : __DIR__"wuchangge",
	]));
	set("objects",([
	         __DIR__"npc/saodiseng" : 1,
	]));

        set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

inherit ROOM;

void create()
{
        set("short", "��̳��");
        set("long",@LONG
����ɮ���ǵ㻯��ͽ�ĵط������ٽ���������������˴��ɱɱ
�����ӣ������˴��䷢Ϊɮ���������š�ǽ��һ�������������߸�
��һ���������飺�������������سɷ�
LONG
        );
        set("exits", ([
                "west" : __DIR__"shijie2",
		"north" : __DIR__"huangtianmen",
	]));
	set("objects",([
		__DIR__"npc/xing-feng" : 1,
                __DIR__"npc/xiaoshami" : 2,
	]));

        set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",10);
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

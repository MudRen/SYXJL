// guandao1.c �ٵ�
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ�����������ͨ���书�򡣵��ϵ����˺ܶ࣬����ǵ���ͷ
�Լ����Լ���·����Ȼ������������õõ�����������һ�������ƥ
���������߷ɳ۶�����������һƬ��ɳ��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "west" : __DIR__"guandao2",
                "east" : __DIR__"daguandao",
        ]));
        set("no_clean_up", 0);
        set("coor/x",-70);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-70);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-70);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-70);
	set("coor/y",130);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}



// fu-damen ���Ҵ���
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "���Ҵ���");
        set("long", @LONG
�������书�����׸�--��Ա��ҵĴ��ţ����Ϲ���һ�����ң�����
д�š�����������֡���������һ������Ӱ�ڣ�ģģ������������һ
Щʫ��֮��Ķ�����������ü���۵ļҶ���ͦ��͹�ǵ�վ���ſ�ҫ��������
��������һ��Ϊ�����ʵ������аԡ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"dongjie",
                "south" : __DIR__"fu-xiaoyuan",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 3,
        ]));

        set("coor/x",-100);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",120);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


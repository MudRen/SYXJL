//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
		"�����������Ŷ��������������ܻ���û�����̣�������Լ���ܿ����߰�\n"
		"��Ѫ����ż���ܿ����ļ������ƺ�Ҳ���˽��ı�����һ�����������ŵġ�¶\n"
		"�����һ���޴��¯�ӣ�ð����������ף����ҵ���������һ����ѣ��ԭ\n"
		"�������������ڼ�����������\n"	
        );
        set("exits", ([
                "south" : "/d/xingxiu/shamo3",
        ]));

	set("objects",([__DIR__"npc/shijian" :1,]));

        set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
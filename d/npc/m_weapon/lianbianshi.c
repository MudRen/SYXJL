//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "���̶");
        set("long",
		"�����������Ŷ��Ĵ���ֱ޵ĵط������ڻ������̵ĸ��̲�ϡ���Ȼ������\n"
		"��һ��Ư����̶ˮ���������˲��ò���̾����Ȼ�Ĺ��񹤡�̶������վ��һλ\n"
		"�������Ů�����а�����һ�ѿ��Ƽ��Ƿ�����ذ�ף������Ŀ��������̶ˮ����\n"
        );
        set("exits", ([
                "north" : "/d/xingxiu/nanjiang3",
        ]));

	set("objects",([__DIR__"npc/shibian" :1,]));

        set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

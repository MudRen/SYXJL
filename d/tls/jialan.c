// jialan.c

inherit ROOM;

void create()
{
        set("short", "٤����");
        set("long", @LONG
�������Ļ���٤�������й����Ų�˹��������������̫�ӣ���
��Ϊ���¶����ߡ��������๩����ʮ��λ٤�����������ֱַ�Ϊ������
��������ģ�̾�̾����Ħ���������̾�����룬��������ū���̵£�
��Ŀ�����ۣ����������ӣ���ۡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"sanwugong",
                "west" : __DIR__"shengdian",
]));
        set("objects", ([
                __DIR__"npc/bencan": 1,
])); 
        set("no_clean_up", 0);
        set("coor/x",-70);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-70);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-70);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-70);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="west" && (!me->query("family") 
                || me->query("family")["family_name"]!="������"))
                return notify_fail("·�м�����һ����ʯ����������д�����������µ��ӣ�������롣\n");
        return ::valid_leave(me,dir);
}

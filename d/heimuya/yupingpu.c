inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������٣�����ľ����������Ա��⣬һ������Ө����
���ٲ�������к��������˵���������ɶ�������ϴ�칬������������
�µؽ������е�ʥˮ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
		"east" : __DIR__"lianhua",
		"westdown" : __DIR__"baizhang",
		"north" : __DIR__"guanpu",
]));
set("objects", ([
                __DIR__"npc/wolf": 1,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 

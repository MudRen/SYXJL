// Room: /d/shaolin/donglang2.c
// By Marz 04/01/96 

inherit ROOM;


//void init();
//int close_men();
//int force_open(object);
//int do_push(string arg);
//int do_knock(string arg);
//int valid_leave(object, string);
//string look_men();


void create()
{
    set("short", "ʮ����̨");
    set("long", @LONG
������һ������ʯ���ϣ��ϱ���һ���߸ߵ���¥�������������Ǻÿ�����
����һ����(door)�������������š������Ǽ��������͵����ӣ�ʮ�ֵ����ţ���
��Ʈ��һ����Ĳ��㣬��������ϸ��ز�֪˵��Щʲô������Ů���ӣ��Գԣ�Ц
��������
LONG
    );

    set("exits", ([
	"north" : __DIR__"zijincheng",
	"south" : __DIR__"santian",
	"west" : __DIR__"chashi2",
	"east" : __DIR__"xiuxishi1",
    ]));
                                                    
//    set("item_desc",([
//        "men"        :    (: look_men :),
//    ]));
    
    set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",230);
	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",230);
	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",230);
	setup();
}

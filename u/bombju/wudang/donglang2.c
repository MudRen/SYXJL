// Room: /d/shaolin/donglang2.c
// By Marz 04/01/96 

inherit ROOM;


//void init();
//void close_men();
//void force_open(object);
//int do_push(string arg);
//int do_knock(string arg);
//int valid_leave(object, string);
//string look_men();


void create()
{
    set("short", "��������");
    set("long", @LONG
������һ�������ϣ���Լ�����������ߴ������������ƺ���������������
����������һ����(door)�������������š��ϱ��Ǽ��������͵����ӣ�ʮ�ֵ�
���š�����Ʈ��һ����Ĳ��㣬��������ϸ��ز�֪˵��Щʲô������Ů����
���Գԣ�Ц��������
LONG
    );

    set("exits", ([
	"east" : __DIR__"liangongfang",
	"south" : __DIR__"chashi1",
	"west" : __DIR__"donglang1",
	"north" : __DIR__"xiuxishi2",
    ]));
                                                    
//    set("item_desc",([
//        "men"        :    (: look_men :),
//    ]));
    
    set("coor/x",-30);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-30);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-30);
	set("coor/y",90);
	set("coor/z",180);
	setup();
}

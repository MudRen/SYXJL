// oooc: 1998/08/5 



inherit ROOM;



void create()

{

        set("short", "��ɽ");

        set("long", @LONG

���ɽ���չ�������·������۵Ĺ�â���Ե�ʮ�����������ﵽ������

��ѩ����ɽ�Ĵ���½����֮ɽ��һ����ȥ��������ɣ��ݳ���ʮ�ɣ���

ɽ�ϻ�����������ʱ�㿴��ǰ��һС����������Ʈ������Ĵ��������治

Զ֮������Χ�����˱���

LONG

        );



        set("exits", ([

                "east" : __DIR__"bingshan",

                "south" : __DIR__"bingshan3",

                "north" : __DIR__"bingshan3",

                "west" : __DIR__"bingshan",

        ]));





        setup();

        replace_program(ROOM);

}


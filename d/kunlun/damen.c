// room: /kunlun/damen.c
inherit ROOM;

void create()
{
        set("short", "��ʥ�ô���");
        set("long", @LONG
�����������ɸ���֮����ʥ�õĴ��ţ��������Դ���ʦ������ʥ�������
ɽ����, ��������ȵ��, �Ѿ���Ϊ��������Ĵ����ɣ���������������������
����Ҳ�������еĶ������֡��˴�����װ諼��, ȴ���ƺ�ΰ�������彣�ĵ�
�����ſ�������������һ��޴���Ҷ�(bian)��
LONG
        );

set ("objects",(["/d/kunlun/npc/kl-dizi3.c":2]));
        set("item_desc", ([
               "bian"    : "���������Ծ���ΰ�Ĵ��֡��� ʥ �á�\n",
        ]));
        set("exits", ([
                "enter" : __DIR__"qianting",
                "south" :__DIR__"shanmen",
        ]));

        set("coor/x",-180);
	set("coor/y",50);
	set("coor/z",30);
	set("coor/x",-180);
	set("coor/y",50);
	set("coor/z",30);
	set("coor/x",-180);
	set("coor/y",50);
	set("coor/z",30);
	setup();
//       "/clone/board/kunlun_b"->foo();
        replace_program(ROOM);
}


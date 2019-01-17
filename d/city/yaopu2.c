// Room: /d/city/yaopu.c
// YBL 2000/07/27
inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С
������ɢ�������ġ���ҽƽһָ���ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�
һ��С���վ�ڹ�̨���к��Ź˿͡���̨������һ�ŷ��ƵĹ��(guanggao)
��һ������������(paizi)�����������ݳǵ������ҡ�
LONG);

        set("no_fight", 1);
        set("no_study", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);
       set("no_dexmove",1);
        set("no_yun",1);
        set("no_shot","���ڹ��ڳ��ϷŰ�����������ˣ�");

        set("item_desc", ([
                "paizi" : "���������ƽ�\n",
        ]));

        set("objects", ([
                  __DIR__"npc/huoji" : 1,
        ]));

        set("exits", ([
                "south"  : __DIR__"dongdajie2",
                "north" : __DIR__"yaopu1",
        ]));

}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
   notify_fail("��Ƶ��������ǰ��Ц��˵���������ȸ�֢��\n");

        if ( me->query_temp("rent_paid") && dir == "west" )
  notify_fail("���һ����ס��˵�����ϻ�û��������������ˣ�\n");

        return ::valid_leave(me, dir);
}




// Room: /jingzhou/mujiangpu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "ľ����");
        set("long", @LONG
����һ�Ҽ�ª��ľ���̣�һ������ľ�������ڵ��϶����������Ϻ�ǽ��
���ҵضѷ���һЩ���ӣ����ӣ��չ�ʲô�ģ����м����ƺ��Ǿ��ӣ�����һ
���ľ�����ߡ�Ҳ��֪��Ϊʲô����˵�����ľ�����������ľ��ľ������
��ӭ��
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"yingdulu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
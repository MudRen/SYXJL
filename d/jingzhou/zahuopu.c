
// Room: /jingzhou/zahuopu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
���Ǽ�СС���ӻ��̣���Ʒ����������ḻ������һЩ�ճ���Ʒ��
�ƹ�Ц�ݿɾϵ�վ�ڹ�̨�ԣ��к��Ź������ˡ���˵˽������Ҳ��һЩ
�����ù�Ķ�����ǽ�Ϲ���һ������(zhaopai)��
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"sanyijie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

// Room: /jingzhou/jianyudamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����վ�ھ��ݼ����Ĵ��ſڣ������һ�Ÿ߸ߵĺ�ǽ��Ҳ������ͷ���
Ե�ʣ����ſڵļ��������Եú���ɢ���ƺ��ܷ�����Ͱ��ĸ�ǽ���������
�������ܻ�Խ��������û��˭�������λ�ģ���Ϊ����֪�����Թ�Ѻ��һ��
�ǳ���Ҫ�ķ��������棬�ܶ����ˣ������˶��ƺ�������������顣
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"jianyuguodao1",
                "north" : __DIR__"jingnanlu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
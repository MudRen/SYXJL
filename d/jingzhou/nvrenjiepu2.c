
// Room: /jingzhou/nvrenjiepu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ů�˽ֵ���");
        set("long", @LONG
�㻹δ�����ҵ��̵��ţ�һλ��̬���ϵ��ϰ���㽿Ц��ӭ��������
æ������������ܱ������֬��������εغã��������ϰ�������Ҳ���ó�
����Ҫ���Ǵ��õ������������������˿ͣ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"nvrenjie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
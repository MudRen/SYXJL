
// Room: /jingzhou/caishikou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���п�");
        set("long", @LONG
�����߾��ǲ˳��ˣ�����ȴ�ǹٸ���������������ͷ��λ�ã���̨�ϻ�
��Щûϴ�ɾ���������һЩ�����Ѫ������˵���̵Ŀ�����������������һ
�ѿ쵶��������ȴ���µ�����Ψһ��ͽ�ܡ�����ӡ���������������һ����
��ʹ�죬������Ȼϲ���������۵�ͽ�ܵúܣ���Ϊ�������ͽ�ܣ�˽�¸�
����������˲�֪�ж��٣��ֲ��¾����¸���
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "northwest" : __DIR__"zhangjuzhengjie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
// xiandan.c �ɵ�


inherit ITEM

void create()
{
        set_name(HIY �ɵ� NOR, ({ dan, xian dan, xiandan }) )
        set_weight(200)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, һ��԰԰���ɵ�����˵���˿�����ǿ������\n)
                set(value, 10000)
                set(unit, ��)
        }
}

void init()
{
        add_action(do_eat, eat)
}

int do_eat(string arg)
{
        object me

        if (! id(arg))
                return notify_fail(��Ҫ��ʲô��\n)

        message_vision($Nһ������������һ�� + this_object()->name() +
                       "��\n", me)
        if (me->query(gift/xiandan) >= 100)
        {
                message_vision($N��Ȼ�����ۡ�������һ�ء�\n, me)
                tell_object(me, ���������ǳ��Ŀࡣ\n)
        
        } else
        {
                tell_object(me, HIG һ�ɻ�����Ȼ����������
                            "��ͷʹ���ѣ�ǡ�ڴ�ʱһ������֮����Ȼ���𣬶ٸ���̩�ޱȡ�\n")
                me->add(int, 3)
        }

        me->add(gift/xiandan, 1)
        destruct(this_object())
        return 1
}



inherit HAMMER
inherit F_FOOD


void create()
{
        set_name(������, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, һ֦����������ļ��ȡ�\n)
                set(unit, ��)
                  set(value, 10)
                set(combat_exp_remaining, 1000)
                set(combat_exp_supply, 1000)
                set(wield_msg, $Nץ��һ��$n���������е�������\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()
}

int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(�еþ���ļ��ȹ�ͷ, ({ bone }) )
        set_weight(150)
        set(long, һ���еþ���ļ��ȹ�ͷ��\n)
        return 1
}


inherit HAMMER
inherit F_FOOD


void create()
{
        set_name(������, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, һ֦����������ļ��ȡ�\n)
                set(unit, ��)
                  set(value, 10)
                set(combat_exp_remaining, 1000)
                set(combat_exp_supply, 1000)
                set(wield_msg, $Nץ��һ��$n���������е�������\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()
}

int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(�еþ���ļ��ȹ�ͷ, ({ bone }) )
        set_weight(150)
        set(long, һ���еþ���ļ��ȹ�ͷ��\n)
        return 1
}

// dumpling.c ����

inherit ITEM
inherit D_DUEST

void create()
{
        set_name(����, ({baozi, dumpling}))
        set_weight(80)
        if (clonep())
                set_default_object(__FILE__)
        else {
                set(long, һ�������������ӡ�\n)
                set(unit, ��)
                  set(value, 10)
                set(combat_exp, 3)
                set(combat_exp, 20)
        }
}

// dumpling.c ����

inherit ITEM
inherit F_FOOD

void create()
{
        set_name(����, ({baozi, dumpling}))
        set_weight(80)
        if (clonep())
                set_default_object(__FILE__)
        else {
                set(long, һ�������������ӡ�\n)
                set(unit, ��)
                  set(value, 10)
                set(combat_exp, 3)
                set(combat_exp, 20)
        }
inherit HAMMER
inherit F_FOOD

void create()
{
        set_name(������, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, һ֦����������ļ��ȡ�\n)
                set(unit, ��)
                  set(value, 10)
                set(combat_exp, 1000)
                set(combat_exp, 1000)
                set(wield_msg, $Nץ��һ��$n���������е�������\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()


int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(�еþ���ļ��ȹ�ͷ, ({ bone }) )
        set_weight(150)
        set(long, һ���еþ���ļ��ȹ�ͷ��\n)
        return 1
}

inherit HAMMER
inherit F_FOOD

void create()
{
        set_name(������, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, һ֦����������ļ��ȡ�\n)
                set(unit, ��)
                  set(value, 10)
                set(combat_exp, 1000)
                set(combat_exp, 1000)
                set(wield_msg, $Nץ��һ��$n���������е�������\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()


int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(�еþ���ļ��ȹ�ͷ, ({ bone }) )
        set_weight(150)
        set(long, һ���еþ���ļ��ȹ�ͷ��\n)
        return 1
}

inherit HAMMER
inherit F_FOOD

void create()
{
        set_name(������, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, һ֦����������ļ��ȡ�\n)
                set(unit, ��)
                  set(value, 10)
                set(combat_exp, 1000)
                set(combat_exp, 1000)
                set(wield_msg, $Nץ��һ��$n���������е�������\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()
}

int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(�еþ���ļ��ȹ�ͷ, ({ bone }) )
        set_weight(150)
        set(long, һ���еþ���ļ��ȹ�ͷ��\n)
        return 1
}


inherit HAMMER
inherit F_FOOD


void create()
{
        set_name(������, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, һ֦����������ļ��ȡ�\n)
                set(unit, ��)
                  set(value, 10)
                set(food_remaining, 4)
                set(food_supply, 15)
                set(wield_msg, $Nץ��һ��$n���������е�������\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()
}

int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(�еþ���ļ��ȹ�ͷ, ({ bone }) )
        set_weight(150)
        set(long, һ���еþ���ļ��ȹ�ͷ��\n)
        return 1
}

inherit ITEM

string* titles = ({�������,})

void create()
{
        set_name(titlesrandom, ({ dienianhua jianpu, shu, book }))
        set(long, ����һ���ʺ�Ů��ѧϰ�Ľ����ؼ���)
        set_weight(200)
        
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(unit, ��)
                set(long, ����һ���ʺ�Ů��ѧϰ�Ľ����ؼ���\n)
                set(value, 500)
                set(unique, 1)
                set(material, paper)
                set(no_get,1)
                set(no_put,1)

        }
}
void init()
{
        add_action(do_du, du)
        add_action(do_du, study)
}    
int do_du(string arg)
{
        object me = this_player()
        object where = environment(me)
  
        int dzlevel
        int neili_lost
        if (!(arg==dienianhua jianpu ||arg==book || arg==shu))
        return 0

        if (where->query(pigging)){
                write(�㻹��ר�Ĺ���ɣ�\n)
                return 1
        }
        if (me->is_busy()) {
                write(��������æ���ء�\n)
                return 1
        }

        if( me->is_fighting() ) {
                write(���޷���ս����ר�������ж���֪��\n)
                return 1
        }

        if (!id(arg)) { 
                write(��Ҫ��ʲô��\n)
                return 1
        }
       
        if( !me->query_skill(literate, 1) ){
                write(���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n)
                return 1
        }

        if( (int)me->query(jing) < 15 ) {
                write(�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n)
                return 1
        }
        if( (int)me->query(neili) < neili_lost) {
                write(�������������޷�������ô������书��\n)
                return 1
        }

        if( (int)me->query(combat_exp) < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write(���ʵս���鲻�㣬����ô��Ҳû�á�\n)
                return 1
        }
        if ( me->query_skill(dienianhua-jian, 1) > 200) {
        write(���Ѿ��޷����Ȿ�������򵽸�������书�ˡ�\n)
        return 1;}
                me->receive_damage(jing, 15)
                me->set(neili,(int)me->query(neili)-neili_lost)
                me->improve_skill(dienianhua-jian, (int)me->query_skill(parry, 1)/3+1)
                write(��������ϰ����������书�ؼ����ƺ��е��ĵá�\n)
                return 1
                
}

inherit ITEM

string* titles = ({
        "�������",
})

void create()
{
        set_name(titlesrandom, ({ dienianhua jianpu, shu, book }))
        set(long, 
����һ���ʺ�Ů��ѧϰ�Ľ����ؼ���
")
        set_weight(200)
        
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(unit, ��)
                set(long, ����һ���ʺ�Ů��ѧϰ�Ľ����ؼ���\n)
                set(value, 500)
                set(unique, 1)
                set(material, paper)
                set(no_get,1)
                set(no_put,1)

        }
}
void init()
{
        add_action(do_du, du)
        add_action(do_du, study)
}    
int do_du(string arg)
{
        object me = this_player()
        object where = environment(me)
  
        int dzlevel
        int neili_lost
        if (!(arg==dienianhua jianpu ||arg==book || arg==shu))
        return 0

        if (where->query(pigging)){
                write(�㻹��ר�Ĺ���ɣ�\n)
                return 1
        }
        if (me->is_busy()) {
                write(��������æ���ء�\n)
                return 1
        }

        if( me->is_fighting() ) {
                write(���޷���ս����ר�������ж���֪��\n)
                return 1
        }

        if (!id(arg)) { 
                write(��Ҫ��ʲô��\n)
                return 1
        }
       
        if( !me->query_skill(literate, 1) ){
                write(���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n)
                return 1
        }

        if( (int)me->query(jing) < 15 ) {
                write(�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n)
                return 1
        }
        if( (int)me->query(neili) < neili_lost) {
                write(�������������޷�������ô������书��\n)
                return 1
        }

        if( (int)me->query(combat_exp) < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write(���ʵս���鲻�㣬����ô��Ҳû�á�\n)
                return 1
        }
        if ( me->query_skill(dienianhua-jian, 1) > 200) {
        write(���Ѿ��޷����Ȿ�������򵽸�������书�ˡ�\n)
        return 1;}
                me->receive_damage(jing, 15)
                me->set(neili,(int)me->query(neili)-neili_lost)
                me->improve_skill(dienianhua-jian, (int)me->query_skill(parry, 1)/3+1)
                write(��������ϰ����������书�ؼ����ƺ��е��ĵá�\n)
                return 1
                
}

inherit ITEM

string* titles = ({
        "�������",
})

void create()
{
        set_name(titlesrandom, ({ dienianhua jianpu, shu, book }))
        set(long, 
����һ���ʺ�Ů��ѧϰ�Ľ����ؼ���
")
        set_weight(200)
        
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(unit, ��)
                set(long, ����һ���ʺ�Ů��ѧϰ�Ľ����ؼ���\n)
                set(value, 500)
                set(unique, 1)
                set(material, paper)
                set(no_get,1)
                set(no_put,1)

        }
}
void init()
{
        add_action(do_du, du)
        add_action(do_du, study)
}    
int do_du(string arg)
{
        object me = this_player()
        object where = environment(me)
  
        int dzlevel
        int neili_lost
        if (!(arg==dienianhua jianpu ||arg==book || arg==shu))
        return 0

        if (where->query(pigging)){
                write(�㻹��ר�Ĺ���ɣ�\n)
                return 1
        }
        if (me->is_busy()) {
                write(��������æ���ء�\n)
                return 1
        }

        if( me->is_fighting() ) {
                write(���޷���ս����ר�������ж���֪��\n)
                return 1
        }

        if (!id(arg)) { 
                write(��Ҫ��ʲô��\n)
                return 1
        }
       
        if( !me->query_skill(literate, 1) ){
                write(���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n)
                return 1
        }

        if( (int)me->query(jing) < 15 ) {
                write(�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n)
                return 1
        }
        if( (int)me->query(neili) < neili_lost) {
                write(�������������޷�������ô������书��\n)
                return 1
        }

        if( (int)me->query(combat_exp) < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write(���ʵս���鲻�㣬����ô��Ҳû�á�\n)
                return 1
        }
        if ( me->query_skill(dienianhua-jian, 1) > 200) {
        write(���Ѿ��޷����Ȿ�������򵽸�������书�ˡ�\n)
        return 1;}
                me->receive_damage(jing, 15)
                me->set(neili,(int)me->query(neili)-neili_lost)
                me->improve_skill(dienianhua-jian, (int)me->query_skill(parry, 1)/3+1)
                write(��������ϰ����������书�ؼ����ƺ��е��ĵá�\n)
                return 1
                
}


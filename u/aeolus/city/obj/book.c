// xiandan.c 仙丹


inherit ITEM

void create()
{
        set_name(HIY 仙丹 NOR, ({ dan, xian dan, xiandan }) )
        set_weight(200)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, 一颗园园的仙丹，据说吃了可以增强智力。\n)
                set(value, 10000)
                set(unit, 颗)
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
                return notify_fail(你要吃什么？\n)

        message_vision($N一仰脖，吞下了一颗 + this_object()->name() +
                       "。\n", me)
        if (me->query(gift/xiandan) >= 100)
        {
                message_vision($N忽然“哇哇”，吐了一地。\n, me)
                tell_object(me, 你觉得嘴里非常的苦。\n)
        
        } else
        {
                tell_object(me, HIG 一股火热蓦然从脑中升起，
                            "你头痛欲裂，恰在此时一股清凉之意油然而起，顿感舒泰无比。\n")
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
        set_name(烤鸡腿, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, 一枝烤得香喷喷的鸡腿。\n)
                set(unit, 根)
                  set(value, 10)
                set(combat_exp_remaining, 1000)
                set(combat_exp_supply, 1000)
                set(wield_msg, $N抓起一根$n，握在手中当武器。\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()
}

int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(啃得精光的鸡腿骨头, ({ bone }) )
        set_weight(150)
        set(long, 一根啃得精光的鸡腿骨头。\n)
        return 1
}


inherit HAMMER
inherit F_FOOD


void create()
{
        set_name(烤鸡腿, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, 一枝烤得香喷喷的鸡腿。\n)
                set(unit, 根)
                  set(value, 10)
                set(combat_exp_remaining, 1000)
                set(combat_exp_supply, 1000)
                set(wield_msg, $N抓起一根$n，握在手中当武器。\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()
}

int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(啃得精光的鸡腿骨头, ({ bone }) )
        set_weight(150)
        set(long, 一根啃得精光的鸡腿骨头。\n)
        return 1
}

// dumpling.c 包子

inherit ITEM
inherit D_DUEST

void create()
{
        set_name(包子, ({baozi, dumpling}))
        set_weight(80)
        if (clonep())
                set_default_object(__FILE__)
        else {
                set(long, 一个香喷喷的肉包子。\n)
                set(unit, 个)
                  set(value, 10)
                set(combat_exp, 3)
                set(combat_exp, 20)
        }
}

// dumpling.c 包子

inherit ITEM
inherit F_FOOD

void create()
{
        set_name(包子, ({baozi, dumpling}))
        set_weight(80)
        if (clonep())
                set_default_object(__FILE__)
        else {
                set(long, 一个香喷喷的肉包子。\n)
                set(unit, 个)
                  set(value, 10)
                set(combat_exp, 3)
                set(combat_exp, 20)
        }
inherit HAMMER
inherit F_FOOD

void create()
{
        set_name(烤鸡腿, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, 一枝烤得香喷喷的鸡腿。\n)
                set(unit, 根)
                  set(value, 10)
                set(combat_exp, 1000)
                set(combat_exp, 1000)
                set(wield_msg, $N抓起一根$n，握在手中当武器。\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()


int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(啃得精光的鸡腿骨头, ({ bone }) )
        set_weight(150)
        set(long, 一根啃得精光的鸡腿骨头。\n)
        return 1
}

inherit HAMMER
inherit F_FOOD

void create()
{
        set_name(烤鸡腿, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, 一枝烤得香喷喷的鸡腿。\n)
                set(unit, 根)
                  set(value, 10)
                set(combat_exp, 1000)
                set(combat_exp, 1000)
                set(wield_msg, $N抓起一根$n，握在手中当武器。\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()


int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(啃得精光的鸡腿骨头, ({ bone }) )
        set_weight(150)
        set(long, 一根啃得精光的鸡腿骨头。\n)
        return 1
}

inherit HAMMER
inherit F_FOOD

void create()
{
        set_name(烤鸡腿, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, 一枝烤得香喷喷的鸡腿。\n)
                set(unit, 根)
                  set(value, 10)
                set(combat_exp, 1000)
                set(combat_exp, 1000)
                set(wield_msg, $N抓起一根$n，握在手中当武器。\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()
}

int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(啃得精光的鸡腿骨头, ({ bone }) )
        set_weight(150)
        set(long, 一根啃得精光的鸡腿骨头。\n)
        return 1
}


inherit HAMMER
inherit F_FOOD


void create()
{
        set_name(烤鸡腿, ({ jitui, tui }) )
        set_weight(350)
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(long, 一枝烤得香喷喷的鸡腿。\n)
                set(unit, 根)
                  set(value, 10)
                set(food_remaining, 4)
                set(food_supply, 15)
                set(wield_msg, $N抓起一根$n，握在手中当武器。\n)
                set(material, bone)
        }
        init_hammer(1)
        setup()
}

int finish_eat()
{
        if( !query(weapon_prop) ) return 0
        set_name(啃得精光的鸡腿骨头, ({ bone }) )
        set_weight(150)
        set(long, 一根啃得精光的鸡腿骨头。\n)
        return 1
}

inherit ITEM

string* titles = ({蝶念花剑谱,})

void create()
{
        set_name(titlesrandom, ({ dienianhua jianpu, shu, book }))
        set(long, 这是一本适合女子学习的剑法秘籍。)
        set_weight(200)
        
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(unit, 本)
                set(long, 这是一本适合女子学习的剑法秘籍。\n)
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
                write(你还是专心拱猪吧！\n)
                return 1
        }
        if (me->is_busy()) {
                write(你现在正忙着呢。\n)
                return 1
        }

        if( me->is_fighting() ) {
                write(你无法在战斗中专心下来研读新知！\n)
                return 1
        }

        if (!id(arg)) { 
                write(你要读什么？\n)
                return 1
        }
       
        if( !me->query_skill(literate, 1) ){
                write(你是个文盲，先学点文化(literate)吧。\n)
                return 1
        }

        if( (int)me->query(jing) < 15 ) {
                write(你现在过于疲倦，无法专心下来研读新知。\n)
                return 1
        }
        if( (int)me->query(neili) < neili_lost) {
                write(你内力不够，无法钻研这么高深的武功。\n)
                return 1
        }

        if( (int)me->query(combat_exp) < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write(你的实战经验不足，再怎么读也没用。\n)
                return 1
        }
        if ( me->query_skill(dienianhua-jian, 1) > 200) {
        write(你已经无法从这本书里领悟到更高深的武功了。\n)
        return 1;}
                me->receive_damage(jing, 15)
                me->set(neili,(int)me->query(neili)-neili_lost)
                me->improve_skill(dienianhua-jian, (int)me->query_skill(parry, 1)/3+1)
                write(你正在研习蝶念花剑法的武功秘籍，似乎有点心得。\n)
                return 1
                
}

inherit ITEM

string* titles = ({
        "蝶念花剑谱",
})

void create()
{
        set_name(titlesrandom, ({ dienianhua jianpu, shu, book }))
        set(long, 
这是一本适合女子学习的剑法秘籍。
")
        set_weight(200)
        
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(unit, 本)
                set(long, 这是一本适合女子学习的剑法秘籍。\n)
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
                write(你还是专心拱猪吧！\n)
                return 1
        }
        if (me->is_busy()) {
                write(你现在正忙着呢。\n)
                return 1
        }

        if( me->is_fighting() ) {
                write(你无法在战斗中专心下来研读新知！\n)
                return 1
        }

        if (!id(arg)) { 
                write(你要读什么？\n)
                return 1
        }
       
        if( !me->query_skill(literate, 1) ){
                write(你是个文盲，先学点文化(literate)吧。\n)
                return 1
        }

        if( (int)me->query(jing) < 15 ) {
                write(你现在过于疲倦，无法专心下来研读新知。\n)
                return 1
        }
        if( (int)me->query(neili) < neili_lost) {
                write(你内力不够，无法钻研这么高深的武功。\n)
                return 1
        }

        if( (int)me->query(combat_exp) < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write(你的实战经验不足，再怎么读也没用。\n)
                return 1
        }
        if ( me->query_skill(dienianhua-jian, 1) > 200) {
        write(你已经无法从这本书里领悟到更高深的武功了。\n)
        return 1;}
                me->receive_damage(jing, 15)
                me->set(neili,(int)me->query(neili)-neili_lost)
                me->improve_skill(dienianhua-jian, (int)me->query_skill(parry, 1)/3+1)
                write(你正在研习蝶念花剑法的武功秘籍，似乎有点心得。\n)
                return 1
                
}

inherit ITEM

string* titles = ({
        "蝶念花剑谱",
})

void create()
{
        set_name(titlesrandom, ({ dienianhua jianpu, shu, book }))
        set(long, 
这是一本适合女子学习的剑法秘籍。
")
        set_weight(200)
        
        if( clonep() )
                set_default_object(__FILE__)
        else {
                set(unit, 本)
                set(long, 这是一本适合女子学习的剑法秘籍。\n)
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
                write(你还是专心拱猪吧！\n)
                return 1
        }
        if (me->is_busy()) {
                write(你现在正忙着呢。\n)
                return 1
        }

        if( me->is_fighting() ) {
                write(你无法在战斗中专心下来研读新知！\n)
                return 1
        }

        if (!id(arg)) { 
                write(你要读什么？\n)
                return 1
        }
       
        if( !me->query_skill(literate, 1) ){
                write(你是个文盲，先学点文化(literate)吧。\n)
                return 1
        }

        if( (int)me->query(jing) < 15 ) {
                write(你现在过于疲倦，无法专心下来研读新知。\n)
                return 1
        }
        if( (int)me->query(neili) < neili_lost) {
                write(你内力不够，无法钻研这么高深的武功。\n)
                return 1
        }

        if( (int)me->query(combat_exp) < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write(你的实战经验不足，再怎么读也没用。\n)
                return 1
        }
        if ( me->query_skill(dienianhua-jian, 1) > 200) {
        write(你已经无法从这本书里领悟到更高深的武功了。\n)
        return 1;}
                me->receive_damage(jing, 15)
                me->set(neili,(int)me->query(neili)-neili_lost)
                me->improve_skill(dienianhua-jian, (int)me->query_skill(parry, 1)/3+1)
                write(你正在研习蝶念花剑法的武功秘籍，似乎有点心得。\n)
                return 1
                
}


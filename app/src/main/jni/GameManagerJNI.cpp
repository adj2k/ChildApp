#include <jni.h>
#include <string>

#include "GameManager.h"
#include "NumbersGame.h"
#include "LettersGame.h"

#include "Expression.h"

game::GameManager gm{0, 0};

extern "C"
JNIEXPORT void JNICALL
Java_com_example_login_ChooseGameActivity_setAgeRangeTo5To7(JNIEnv *env, jobject thiz)
{
    gm.set_age_range(AGE_RANGE_5_TO_7);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_login_ChooseGameActivity_setAgeRangeTo7To8(JNIEnv *env, jobject thiz)
{
    gm.set_age_range(AGE_RANGE_7_to_8);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_login_ChooseGameActivity_setAgeRangeTo8To10(JNIEnv *env, jobject thiz)
{
    gm.set_age_range(AGE_RANGE_8_TO_10);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_login_ChooseGameActivity_startGame(JNIEnv *env, jobject thiz)
{
    gm.start_game();
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_login_GameActivity_getGameDetails(JNIEnv *env, jobject thiz)
{
    return env->NewStringUTF(gm.game->get_game_details().c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_login_GameActivity_getQuestion(JNIEnv *env, jobject thiz)
{
    return env->NewStringUTF(gm.game->curr_question->get_question().c_str());
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_login_GameActivity_submitAnswer(JNIEnv *env, jobject thiz, jstring answer)
{
    jboolean isCopy;
    const char *c_str = (env)->GetStringUTFChars(answer, &isCopy);
    jboolean correct  = gm.game->curr_question->check_answer(std::string(c_str));

    return correct;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_login_GameActivity_correctQuestion(JNIEnv *env, jobject thiz)
{
    gm.game->next_question(1);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_login_GameActivity_incorrectQuestion(JNIEnv *env, jobject thiz)
{
    gm.game->next_question(0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_login_GameActivity_endGame(JNIEnv *env, jobject thiz)
{
    gm.end_game();
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_login_GameActivity_isGameOver(JNIEnv *env, jobject thiz)
{
    return gm.game->results->get_total_questions() >= 25;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_login_GameActivity_getQuestionsAmount(JNIEnv *env, jobject thiz)
{
    std::ostringstream result;
    result << gm.game->results->get_total_questions()+1;
    result << "/25";
    return env->NewStringUTF(result.str().c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_login_GameActivity_getQuestionsTotal(JNIEnv *env, jobject thiz)
{
    return gm.game->results->get_total_questions();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_login_GameActivity_getQuestionsCorrect(JNIEnv *env, jobject thiz)
{
    return gm.game->results->get_correct_questions();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_login_GameActivity_getQuestionsIncorrect(JNIEnv *env, jobject thiz)
{
    return gm.game->results->get_incorrect_questions();
}
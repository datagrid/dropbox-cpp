#ifndef __DROPBOX_ACCOUNT_INFO_H__
#define __DROPBOX_ACCOUNT_INFO_H__

#include <string>

#include <sys/types.h>
namespace dropbox {

struct DropboxQuotaInfo {
  uint64_t    shared;
  uint64_t    quota;
  uint64_t    normal;
};

class DropboxAccountInfo {
public:
  DropboxAccountInfo() { }
  DropboxAccountInfo(std::string& json);

  void            readJson(std::string&);

  std::string         getReferralLink() const;
  std::string         getDisplayName() const;
  std::string         getUid() const;
  std::string         getCountry() const;
  std::string         getEmail() const;
  DropboxQuotaInfo    getQuotaInfo() const;

private:
  static void     readFromJson(DropboxAccountInfo*, std::string& json);

  std::string           referralLink_;
  std::string           displayName_;
  std::string           uid_;
  std::string           country_;
  std::string           email_;
  DropboxQuotaInfo      quotaInfo_;
};
}
#endif

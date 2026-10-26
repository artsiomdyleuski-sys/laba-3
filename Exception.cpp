#pragma once
#include <stdexcept>
#include <string>

class NetworkException : public std::runtime_error {
public: explicit NetworkException(const std::string& m) : std::runtime_error(m) {}
};
class InvalidUserDataException : public NetworkException {
public: explicit InvalidUserDataException(const std::string& m) : NetworkException("InvalidUserData: " + m) {}
};
class ContentNotFoundException : public NetworkException {
public: explicit ContentNotFoundException(const std::string& m) : NetworkException("ContentNotFound: " + m) {}
};
class AccountBannedException : public NetworkException {
public: explicit AccountBannedException(const std::string& m) : NetworkException("AccountBanned: " + m) {}
};
class ConnectionFailureException : public NetworkException {
public: explicit ConnectionFailureException(const std::string& m) : NetworkException("ConnectionFailure: " + m) {}
};
class PostNotFoundException : public NetworkException {
public: explicit PostNotFoundException(const std::string& m) : NetworkException("PostNotFound: " + m) {}
};
class InvalidPostException : public NetworkException {
public: explicit InvalidPostException(const std::string& m) : NetworkException("InvalidPost: " + m) {}
};
class ModerationFailedException : public NetworkException {
public: explicit ModerationFailedException(const std::string& m) : NetworkException("ModerationFailed: " + m) {}
};
class SpamLimitExceededException : public NetworkException {
public: explicit SpamLimitExceededException(const std::string& m) : NetworkException("SpamLimit: " + m) {}
};
class UserNotAvailableException : public NetworkException {
public: explicit UserNotAvailableException(const std::string& m) : NetworkException("UserNotAvailable: " + m) {}
};
class InvalidSubscriptionException : public NetworkException {
public: explicit InvalidSubscriptionException(const std::string& m) : NetworkException("InvalidSubscription: " + m) {}
};
class StorageLimitException : public NetworkException {
public: explicit StorageLimitException(const std::string& m) : NetworkException("StorageLimit: " + m) {}
};